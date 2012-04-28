#include "PhysicsThread.h"


PhysicsThread::PhysicsThread(void)
{
	_delta_time  = 0.0f;
	_isspringforcegenerated = false;

	measureP.x = -10;
	measureP.y = 0;
}


PhysicsThread::~PhysicsThread(void)
{

}


void PhysicsThread::CalculateDeltaTime(){
	//Ensure QueryPerformance is called on a specific core
	SetThreadAffinityMask(thread, 0x1);
	QueryPerformanceFrequency(&_ticksPerSecond);
	QueryPerformanceCounter(&_currentCount);
	SetThreadAffinityMask(thread, procMask);

	_consumedCount.QuadPart = _currentCount.QuadPart - _lastCount.QuadPart;  
	_lastCount = _currentCount;
	_delta_time = float(_consumedCount.QuadPart/(_ticksPerSecond.QuadPart/1000));
#ifdef DEBUG_DELTATIME
	cout<<"ms = "<<_delta_time<<endl;
#endif

}

bool PhysicsThread::CollisionDectectShapeAndGround(const Shape&shape)
{
	int numofsize = shape.sizeofpoints;
	for(int i = 0; i< numofsize; i ++)
	{
		if(shape.points.at(i).y < GROUND_Y)
			return true;
	}
	return false;
}

bool PhysicsThread::CollisionDectectBoxAndTriangle(const Shape&box, const Shape&tri)
{
	return false;
}
bool PhysicsThread::CollisionDectectTriangleAndTriangle(const Shape&tria, const Shape&trib)
{
	return false;
}

bool PhysicsThread::CollisionDectectBoxAndBox(const Shape&boxA,const Shape&boxB)
{
	bool res = false;
	//////////////////////////////////////////////////////////////////////////
	/**
	//fix function
	float deltax = boxA.px - boxB.px;
	float deltay = boxA.py - boxB.py;
	//
	float axis_x = boxA.dx;
	float axis_y = boxA.dy;

	//get boxA.yw project to axis  = 0, so here just only need boxA.xw projected to axis = boxA.xw
	float asize = boxA.xw;

	//get boxB proejct to axis
	float bsize = 0;
	ProjectBox(bsize,boxB,axis_x,axis_y);

	//get delta project to axis
	float dsize = abs(deltax*axis_x + deltay*axis_y);


	//rA + rB  -  dis
	float penAx = (asize + bsize) - dsize;
	//if > 0 ; there is overlap
	if(penAx > 0)
	{
		//boxes overlap along axis; check next axis
		axis_x = boxB.dx;
		axis_y = boxB.dy;

		asize = boxB.xw;
		bsize = 0;
		ProjectBox(bsize,boxA,axis_x,axis_y);
		dsize = abs(deltax*axis_x + deltay*axis_y);
		penAx = (asize + bsize) - dsize;

		if(penAx > 0)
		{
			axis_x = -boxA.dy;
			axis_y = boxA.dx;
			asize = boxA.yw;
			bsize = 0;
			ProjectBox(bsize,boxB,axis_x,axis_y);
			dsize = abs(deltax*axis_x + deltay*axis_y);
			penAx = (asize + bsize) - dsize;

			if(penAx > 0)
			{
				axis_x = -boxB.dy;
				axis_y = boxB.dx;
				asize = boxB.yw;
				bsize = 0;
				ProjectBox(bsize,boxA,axis_x,axis_y);
				dsize = abs(deltax*axis_x + deltay*axis_y);
				penAx = (asize + bsize) - dsize;
				if(penAx > 0)
				{
					res = true;
				}
				else
				{
					res = false;
				}

			}
			else
			{
				res = false;
			}
		}
		else{
			res = false;
		}

	}
	else
	{
		res = false;
	}

	*/
	//////////////////////////////////////////////////////////////////////////
	return res;
}

void PhysicsThread::CalculatePyhsics6()
{
	int objnum = _shapeShareObject->renderObjects.size();

	for(int i = 0; i< objnum;i++)
	{
		bool hitsomething = false;
		Shape* shapeA = _shapeShareObject->renderObjects.at(i);
		//if the shape is ground
		if(shapeA->type ==1)
			continue;

		//////////////////////////////////////////////////////////////////////////
		//checkground
		if(CollisionDectectShapeAndGround(*shapeA))
		{
			//calculate hit ground
			cout<<"hit ground"<<endl;
			hitsomething = true;
			//do next
		}
		else
		{
			for(int j = 0; j < objnum; j++  )
			{
				Shape* shapeB = _shapeShareObject->renderObjects.at(j);
				if(shapeA->id != shapeB->id)
				{
					//do Collision dectect
					if(shapeA->type == 2 && shapeB->type == 2)
					{
						// triangle hit triangle
						hitsomething = true;
					}
					if(shapeA->type == 2 && shapeB->type == 3)
					{
						//triangle hit box
						hitsomething = true;
					}
					if(shapeA->type == 3 && shapeB->type == 2)
					{
						//box hit triangle
						hitsomething = true;
					}
					if(shapeA->type == 3 && shapeB->type == 3 && CollisionDectectBoxAndBox(*shapeA,*shapeB))
					{
						//box hit box
						hitsomething = true;
					}

				}
			}

		}
		//////////////////////////////////////////////////////////////////////////
		//add spring force

		//////////////////////////////////////////////////////////////////////////
		if(!hitsomething)
		{
			//remove foece shake
			if(shapeA->force.x < 0.00001)
			{
				shapeA->force.x = 0;
			}
			if(shapeA->force.y < 0.00001)
			{
				shapeA->force.y = 0;
			}
			//no hit, do the work free fly
			shapeA->acceleration.x = shapeA->force.x / shapeA->mass; 
			shapeA->acceleration.y = shapeA->force.y / shapeA->mass;
			//
		}

		//////////////////////////////////////////////////////////////////////////



		//////////////////////////////////////////////////////////////////////////

	}


}

void PhysicsThread::CalculatePyhsics7()
{
	//A is host b is guest
	int objnum = _shapeShareObject->renderObjects.size();
	for(int i=0;i<objnum;i++)
	{
		Shape* shapeA = _shapeShareObject->renderObjects.at(i);
		if (shapeA->type != 1)
		{
			//make sure A is not ground

			for(int j = 0; j<objnum;j++)
			{
				Shape* shapeB = _shapeShareObject->renderObjects.at(j);
				//shapeB maybe ground
				if(shapeA->id != shapeB->id)
				{
					CollisionDectect(*shapeA,*shapeB);

				}
				else
				{
					continue;
				}

			}
		}
		else
		{
			continue;
		}
		
	}
}

void PhysicsThread::CollisionDectect(const Shape& shapeA, const Shape& shapeB)
{
	bool iscollision = false;

	//check collision and response
	//get num of shapeA's axis
	int numofaxisA = shapeA.project_axis.size();
	int numofaxisB = shapeB.project_axis.size();
	//
	//fix function, get delta
	float deltax = shapeA.pos.x - shapeB.pos.x;
	float deltay = shapeA.pos.y - shapeB.pos.y;
	if(shapeB.type != 1)
	{
		//
		for(int i = 0;i< numofaxisA; i++)
		{
			float Adx = shapeA.project_axis.at(i).x;
			float Ady = shapeA.project_axis.at(i).y;
			float Alen = shapeA.project_axis.at(i).z;

			float asize = Alen;
			float bsize = 0;
			ProjectShape(bsize,shapeB,Adx,Ady);

			//get delta project to axis
			float dsize = abs(deltax*Adx + deltay*Ady);
			//rA + rB  -  dis
			float penAx = (asize + bsize) - dsize;

			if(penAx>0)
			{
				//over lap
				iscollision = true;
			}
			else
			{
				iscollision = false;
				break;
			}

		}
		if(iscollision)
		{
			//check B axis
			for(int i = 0;i< numofaxisB; i++)
			{
				float Bdx = shapeB.project_axis.at(i).x;
				float Bdy = shapeB.project_axis.at(i).y;
				float Blen = shapeB.project_axis.at(i).z;

				float asize = Blen;
				float bsize = 0;
				ProjectShape(bsize,shapeA,Bdx,Bdy);

				//get delta project to axis
				float dsize = abs(deltax*Bdx + deltay*Bdy);

				//rA + rB  -  dis
				float penAx = (asize + bsize) - dsize;

				if(penAx>0)
				{
					//over lap
					iscollision = true;
				}
				else
				{
					iscollision = false;
					break;
				}

			}
		}
	}
	else
	{
		//shapeB is ground
		float Bdx = shapeB.project_axis.at(0).x;
		float Bdy = shapeB.project_axis.at(0).y;

		float bsize = 0;
		ProjectShape(bsize,shapeA,Bdx,Bdy);
		//deltay
		float asize = 0;

		float dsize = abs(deltay);

		float penAx = (asize + bsize)-dsize;

		if(penAx>0)
		{
			iscollision = true;
		}
		else
		{
			iscollision = false;
		}

	}
	


	if(iscollision)
	{
		//do response
		cout<<"hit"<<endl;
	}
	else
	{
		//continue to work
	}



}
void PhysicsThread::ProjectShape(float&bsize, const Shape& shape, const float&ax,const float&ay)
{
	int numofaxis = shape.project_axis.size();
	bsize = 0;
	for(int i = 0;i<numofaxis;i++)
	{
		float dx = shape.project_axis.at(i).x;
		float dy = shape.project_axis.at(i).y;
		float len = shape.project_axis.at(i).z;
		//
		float ix = len*dx;
		float iy = len*dy;

		float dpi = ix * ax + iy * ay;

		bsize = bsize + abs(dpi);
	}
	/**
	//ax ay is unit vector or direction vector
	float ix = box.xw * box.dx;
	float iy = box.xw * box.dy;

	float jx = box.yw * -box.dy;
	float jy = box.yw * box.dx;
	//x project to the axis
	float dpi = ix*ax + iy*ay;
	//y project to the axis
	float dpj = jx*ax + jy*ay;

	bsize = abs(dpi) + abs(dpj);
	*/
}


int PhysicsThread::run(){
	//get sticks per second
	GetProcessAffinityMask(GetCurrentProcess(), &procMask, &sysMask);
	thread = GetCurrentThread();

	while(!_terminate){
		/*cout<<"physics"<<endl;*/
		Sleep(2);
		
		//
		if(_shapeShareObject->Acquire()){
			__try{
				//only get the access,then calculate the time _delta_time
				CalculateDeltaTime();
				if(_delta_time <10000 ){
					//get spring length
					_springforce.length = Dis(_shapeShareObject->springstartp,_shapeShareObject->springendp);
					if(!_shapeShareObject->left_hold && _springforce.length >0){
						/*cout<<"L = "<<springlength<<endl;*/
						//get spring force
						_springforce.allforce = SPRING_FACTOR * _springforce.length;
						//get force direction
						_springforce.dir_x = _shapeShareObject->springendp.x - _shapeShareObject->springstartp.x;
						_springforce.dir_y = _shapeShareObject->springendp.y - _shapeShareObject->springstartp.y;
						//computing force x y
						float dd = sqrt(_springforce.dir_x * _springforce.dir_x + _springforce.dir_y * _springforce.dir_y);
						_springforce.force_x = _springforce.dir_x * _springforce.allforce / dd;
						_springforce.force_y = _springforce.dir_y * _springforce.allforce / dd;
						//save the position to a Point, easy to computing later
						_springforceworkposition.x = _shapeShareObject->springstartp.x;
						_springforceworkposition.y = _shapeShareObject->springstartp.y;
						/*cout<<"clear spring"<<endl;*/
						//after save the current spring variables, clear the variables in shareobject
						_shapeShareObject->springstartp.x = 10;
						_shapeShareObject->springstartp.y = 10;
						_shapeShareObject->springendp.x = 10;
						_shapeShareObject->springendp.y = 10;
						_springforce.allforce = 0;
						//mark
						_isspringforcegenerated = true;
					}
					else
					{
						_isspringforcegenerated = false;
					}
					//////////////////////////////////////////
					//start to compute the physics
					CalculatePyhsics7();
					
				}

			}__finally{
				_shapeShareObject->Release();
			}
		}



	}
	return 0;
}

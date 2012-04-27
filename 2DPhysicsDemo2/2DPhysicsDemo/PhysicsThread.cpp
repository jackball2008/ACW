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



void PhysicsThread::ProjectBox(float&bsize, const Shape& box, const float&ax,const float&ay)
{
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



bool PhysicsThread::CollisionDectect(const Shape& boxA, const Shape&boxB)
{
	return false;

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
					CalculatePyhsics6();
					
				}

			}__finally{
				_shapeShareObject->Release();
			}
		}



	}
	return 0;
}
void PhysicsThread::CalculatePyhsics5()
{
	//
	int objnum = _shapeShareObject->renderObjects.size();
	//add spring
	if(_isspringforcegenerated)
	{
		
		for(int i = 0; i< objnum;i++)
		{
			Shape* shape = _shapeShareObject->renderObjects.at(i);
			/*vector<YPoint>& pa = shape->points;*/
			if(JudgePointInPologon(shape->points,_springforceworkposition,measureP))
			{
				cout<<"s in id = "<<shape->id<<" x = "<<_springforce.force_x<<"y = "<<_springforce.force_y<<endl;
				//add spring force
				shape->springforce.x = _springforce.force_x;
				shape->springforce.y = _springforce.force_y;

				break;
			}
		}
	}
	//computing all force
	for(int i = 0; i< objnum;i++)
	{


		Shape* shape = _shapeShareObject->renderObjects.at(i);
		//////////////////////////////////////////////////////////////////////////
		shape->force.x = 0;
		shape->force.y = 0;
		shape->force.x = shape->force.x + shape->springforce.x;
		shape->force.y = shape->mass * G_ACCERLATION + shape->springforce.y;

		shape->springforce.x = 0;
		shape->springforce.y = 0;
		//////////////////////////////////////////////////////////////////////////
		//a
		shape->acceleration.x = shape->force.x / shape->mass;
		shape->acceleration.y = shape->force.y / shape->mass;
		//clear force for used in the next run
		shape->force.x = 0;
		shape->force.y = 0;
		//////////////////////////////////////////////////////////////////////////
		//save old v
		shape->old_velocity.x = shape->velocity.x;
		shape->old_velocity.y = shape->velocity.y;
		//get new v
		shape->velocity.x = shape->old_velocity.x + shape->acceleration.x * (_delta_time );
		shape->velocity.y = shape->old_velocity.y + shape->acceleration.y * (_delta_time );

		//get movement
		shape->movement.x = float(shape->old_velocity.x * _delta_time + 0.5 * shape->acceleration.x * _delta_time * _delta_time);
		shape->movement.y = float(shape->old_velocity.y * _delta_time + 0.5 * shape->acceleration.y * _delta_time * _delta_time);
		//clear accleration
		shape->acceleration.x = 0;
		shape->acceleration.y = 0;
		//computing new position
		//shape->UpdatePosition();

	}
	

	for(int i = 0; i< objnum;i++)
	{
		Shape* shape = _shapeShareObject->renderObjects.at(i);
		
		//checkground
		CheckHitGround(shape);
		
	}

	for(int i = 0; i <(objnum - 1);i++)
	{
		Shape* A = _shapeShareObject->renderObjects.at(i);
		
		for(int j = i+1; j < objnum; j++  )
		{
			Shape* B = _shapeShareObject->renderObjects.at(j);

			CheckCollision(A,B);
		}

	}

}
void PhysicsThread::CheckCollision(Shape* shapeA, Shape* shapeB)
{
	float dy = shapeB->middlepoint.y - shapeA->middlepoint.y;
	float dx = shapeB->middlepoint.x - shapeA->middlepoint.x;
	float dist = sqrt(dx*dx + dy*dy);

	if(ProjectCollisionDetect2(*shapeA,*shapeB))
	{
		///x
		shapeA->velocity.x = ((shapeA->mass - shapeB->mass) * shapeA->velocity.x + 2 * shapeB->mass * shapeB->velocity.x ) / (shapeA->mass + shapeB->mass);
		shapeB->velocity.x = ((shapeB->mass - shapeA->mass) * shapeA->velocity.x + 2 * shapeA->mass * shapeA->velocity.x ) / (shapeA->mass + shapeB->mass);
		
		//y
		shapeA->velocity.y = ((shapeA->mass - shapeB->mass) * shapeA->velocity.y + 2 * shapeB->mass * shapeB->velocity.y ) / (shapeA->mass + shapeB->mass);
		shapeB->velocity.y = ((shapeB->mass - shapeA->mass) * shapeA->velocity.y + 2 * shapeA->mass * shapeA->velocity.y ) / (shapeA->mass + shapeB->mass);

	}
}
void PhysicsThread::Rotate(const float&x, const float&y, const float&sinv, const float&cosv, const bool&reserve, YPoint&p)
{
	/*YPoint res;*/
	if(reserve)
	{
		p.x = x * cosv + y * sinv;
		p.y = y * cosv - x * sinv;
	}
	else
	{
		p.x = x * cosv - y * sinv;
		p.y = y * cosv + x * sinv;
	}
	/*return res;*/
}
void PhysicsThread::CheckHitGround(Shape* shape)
{
	
	if(ProjectCollisionDetect2(*shape,*(_shapeShareObject->ground)))
	{
		//make v = 0
		shape->velocity.y = 0;
		shape->old_velocity.y = 0;
		shape->movement.y = 0;
		//color
		shape->g = 0.0;
		
	}else
	{
		//color
		shape->g = 1.0;
	}

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

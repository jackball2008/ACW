#include "PhysicsThread.h"


PhysicsThread::PhysicsThread(void)
{
	_delta_time  = 0.0f;
	_old_delta_time = 0.0f;
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
	_old_delta_time = _delta_time;
	_delta_time = float(_consumedCount.QuadPart/(_ticksPerSecond.QuadPart/1000));
	
#ifdef DEBUG_DELTATIME
	cout<<"ms = "<<_delta_time<<endl;
#endif

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

void PhysicsThread::CollisionDectect(Shape& shapeA, Shape& shapeB)
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
		//shapeA hit common shape
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
			//////////////////////////////////////////////////////////////////////////
			ReduceDisMistake(penAx);
			//////////////////////////////////////////////////////////////////////////
			if(penAx>0)
			{
				//over lap
				iscollision = true;
				//save the last penmove value
				//shapeA.project_axis_penAx.at(i) = penAx;
			}
			else
			{
				iscollision = false;
				//shapeA.project_axis_penAx.at(i) = 0;
				break;
			}

		}
		if(iscollision)
		{
			//if all A axis hit, then check all B axis
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
				//////////////////////////////////////////////////////////////////////////
				ReduceDisMistake(penAx);
				//////////////////////////////////////////////////////////////////////////
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
		/**
		float Bdx = shapeB.project_axis.at(0).x;
		float Bdy = shapeB.project_axis.at(0).y;

		float asize = 0;
		ProjectShape(asize,shapeA,Bdx,Bdy);
		
		
		float bsize = 0;

		float dsize = abs(deltay);
		
		float penAx = (asize + bsize)-dsize;

		//reduce mistake made by calculation /////////////////////////////////////
		ReduceDisMistake(penAx);
		//////////////////////////////////////////////////////////////////////////

		if(penAx>0)
		{
			iscollision = true;
			//get penmove value
			shapeA.penmove.y = penAx;
		}
		else
		{
			iscollision = false;
		}
		*/
		if(CollisionDectectShapeAndGround(shapeA))
		{
			iscollision = true;
		}
		else
		{
			iscollision = false;
		}

	}
	//////////////////////////////////////////////////////////////////////////
	//do response
	//////////////////////////////////////////////////////////////////////////
	if(iscollision)
	{
		//do response, change shapeA position velocity acceleration
		
		if(shapeB.type != 1)
		{
			//common hit
			ResponseCollisionWithShape(shapeA,shapeB);
		}
		else
		{
			//ground hit
			ResponseCollisionWithGround(shapeA,shapeB);
		}
	}
	else
	{
		//continue to work, free down
		FreeMoveShape(shapeA);
	}

}
void PhysicsThread::ResponseCollisionWithShape(Shape&shapeA,Shape&shapeB)
{
	//cout<<"common hit"<<endl;
	/**
	float ax = 0;
	float ay = 0;
	float bx = 0;
	float by = 0;
	
	ay = 2*shapeB.mass*shapeB.velocity.y/(shapeA.mass + shapeB.mass);
	ax = 2*shapeB.mass*shapeB.velocity.x/(shapeA.mass + shapeB.mass);

	by = 2*shapeA.mass*shapeA.velocity.y/(shapeA.mass + shapeB.mass);
	bx = 2*shapeA.mass*shapeA.velocity.x/(shapeA.mass + shapeB.mass);

	shapeA.velocity.x = ax;
	shapeA.velocity.y = ay;

	shapeB.velocity.x = bx;
	shapeB.velocity.y = by;
	*/
	//
	float dir = shapeA.velocity.x*shapeB.velocity.x + shapeA.velocity.y * shapeB.velocity.y;
	if(dir>0)
	{
		cout<<"t"<<endl;
	}
	else if(dir<0)
	{
		cout<<"o"<<endl;
	}
	else if (dir == 0)
	{
		cout<<"s"<<endl;
	}
	//get num of axis
	int numofaxisA = shapeA.project_axis.size();

	//fix function, get delta
	float deltax = shapeA.pos.x - shapeB.pos.x;
	float deltay = shapeA.pos.y - shapeB.pos.y;

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
		float penAx = (asize + bsize) - dsize;//amount on the current axis
		//////////////////////////////////////////////////////////////////////////
		ReduceDisMistake(penAx);
		//////////////////////////////////////////////////////////////////////////
	}




}
void PhysicsThread::ResponseCollisionWithGround(Shape&shapeA, const Shape&ground)
{
	//pull back to the ground surface
	shapeA.Move(shapeA.penmove);
	//clear speed, because the speed is changed
	shapeA.velocity.Clear();
	//give it a opposite force
	shapeA.force.y += shapeA.mass * G_ACCERLATION * -1;
	//get the dis between start position and the hit position
	float blankdis = abs(abs(shapeA.movement.y)-abs(shapeA.penmove.y));
	//reduce the dis to save computing
	ReduceDisMistake(blankdis,0.005f);
	//
	//do the bound operation
	if(blankdis!=0)
	{
		float v_g = 0;
		float t_g = 0;
		float t_left = 0;
		//this blankdis is big, need do some thing
		/*cout<<"big hit"<<endl;*/
		//v2 = sqrt(2gh + v1*v1);
		v_g = sqrt(2*G_ACCERLATION*blankdis + shapeA.old_velocity.y * shapeA.old_velocity.y);
		//v2 = v1+gt  t_g < 0
		if(shapeA.old_velocity.y<0) shapeA.old_velocity.y *= -1;
		t_g = (v_g - shapeA.old_velocity.y)/(G_ACCERLATION * -1);
		t_left = _delta_time/1000 - t_g;//ms/1000->s
		/*cout<<t_left<<endl;*/
		//
		shapeA.velocity.y = v_g * FANTAN_XISHU;

		shapeA.force.x = shapeA.force.x;
		shapeA.force.y = shapeA.mass* G_ACCERLATION;

		shapeA.acceleration.x = shapeA.force.x / shapeA.mass;
		shapeA.acceleration.y = shapeA.force.y / shapeA.mass;

		float x_m = float(shapeA.velocity.x * t_left + 0.5 * shapeA.acceleration.x * t_left * t_left);
		float y_m = float(shapeA.velocity.y * t_left + 0.5 * shapeA.acceleration.y * t_left * t_left);

		shapeA.movement.x = x_m;
		shapeA.movement.y = y_m;

		shapeA.Move(shapeA.movement);
	}

	
}

bool PhysicsThread::CollisionDectectShapeAndGround(Shape&shape)
{
	//float Bdx = ground.project_axis.at(0).x;
	//float Bdy = ground.project_axis.at(0).y;
	float deltay = shape.pos.y - GROUND_Y;
	float asize = 0;
	ProjectShape(asize,shape,0,1);
	//float dsize = abs(deltay);//float dsize = abs(deltax*Adx + deltay*Ady);
	float penAx = asize - abs(deltay);
	//reduce mistake made by calculation /////////////////////////////////////
	ReduceDisMistake(penAx);
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* there are four situation for collision with ground
	1. absolute high
	2. overlap high
	3. overlap low
	4. absolute low
	*/
	/************************************************************************/
	
	if(penAx>0)
	{
		//overlap
		if(shape.pos.y > GROUND_Y)
		{
			shape.penmove.y = penAx;
		}
		if(shape.pos.y < GROUND_Y)
		{
			shape.penmove.y = asize + penAx;
		}
		return true;
	}
	else
	{
		
		//no overlap
		if(shape.pos.y > GROUND_Y)
		{
			shape.penmove.y = 0;
			return false;
		}
		if(shape.pos.y < GROUND_Y)
		{
			shape.penmove.y =  asize + abs(deltay);
			return true;
		}

		return false;
	}

	
}

void PhysicsThread::FreeMoveShape(Shape&shape)
{
	float t = _delta_time/1000;//ms -> s
	///
	shape.old_force = shape.force;
	shape.acceleration.x = shape.force.x / shape.mass;
	shape.acceleration.y = shape.force.y / shape.mass + G_ACCERLATION;
	shape.force.Clear();//once the force worked, it just work on this moment, so after it works, clear it
	///
	//YPoint movement;
	shape.old_movement = shape.movement;//maybe not useful
	shape.movement.x = float(shape.velocity.x * t + 0.5 * shape.acceleration.x * t * t);
	shape.movement.y = float(shape.velocity.y * t + 0.5 * shape.acceleration.y * t * t);
	shape.movement.z = 0.0f;
	///get the new speed
	shape.old_velocity = shape.velocity;
	shape.velocity.x = shape.velocity.x + shape.acceleration.x * t;
	shape.velocity.y = shape.velocity.y + shape.acceleration.y * t;
	//////////////////////////////////////////////////////////////////////////
	shape.Move(shape.movement);

}

void PhysicsThread::ReduceDisMistake(float&dis)
{
	if(abs(dis) < NUM_RANGE_HIGH)
		dis = 0;
}
void PhysicsThread::ReduceDisMistake(float&dis,const float&range)
{
	if(abs(dis) < range)
		dis = 0;
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
	
}


int PhysicsThread::run(){
	//get sticks per second
	GetProcessAffinityMask(GetCurrentProcess(), &procMask, &sysMask);
	thread = GetCurrentThread();

	while(!_terminate){
		/*cout<<"physics"<<endl;*/
		Sleep(10);
		
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

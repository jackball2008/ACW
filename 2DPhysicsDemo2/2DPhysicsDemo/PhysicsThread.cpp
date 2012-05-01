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

void PhysicsThread::CollisionDectect(Shape& shapeA, const Shape& shapeB)
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
			}
			else
			{
				iscollision = false;
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
		if(CollisionDectectShapeAndGround(shapeA,shapeB))
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
void PhysicsThread::ResponseCollisionWithShape(Shape&shapeA,const Shape&shapeB)
{
	cout<<"common hit"<<endl;
}
void PhysicsThread::ResponseCollisionWithGround(Shape&shapeA, const Shape&ground)
{
	//shapeA.old_movement.Reverse();
	//shapeA.Move(shapeA.old_movement);
	//shapeA.velocity.Clear();
	/**
	//return the start pos
	shapeA.old_movement.Reverse();
	shapeA.Move(shapeA.old_movement);
	
	//////////////////////////////////////////////////////////////////////////
	//for t/2
	//get used t

	float t = _old_delta_time/2;
	YPoint tempmovement;
	bool findCollisionTime = false;

	float acceleration_x = 0;
	float acceleration_y = 0;

	while(!findCollisionTime)
	{
		
		acceleration_x = shapeA.old_force.x / shapeA.mass;
		acceleration_y = shapeA.old_force.y / shapeA.mass + G_ACCERLATION;
		///
		//YPoint movement;
		tempmovement.x = float(shapeA.old_velocity.x * t + 0.5 * acceleration_x * t * t);
		tempmovement.y = float(shapeA.old_velocity.y * t + 0.5 * acceleration_y * t * t);
		tempmovement.z = 0.0f;
		///
		//////////////////////////////////////////////////////////////////////////
		shapeA.Move(tempmovement);
		//shape.movement.Clear();
		if(CollisionDectectShapeAndGround(shapeA,ground))
		{
			if(shapeA.penmove.y <= EDGE_WIDTH)
			{
				//find the t
				findCollisionTime = true;
				//save the movement
				shapeA.movement.x = tempmovement.x;
				shapeA.movement.y = tempmovement.y;
				shapeA.movement.z = 0;
			}
			else
			{
				//
				t = t/2;
				//return to the start position
				tempmovement.Reverse();
				shapeA.Move(tempmovement);
			}
			
		}
		else
		{
			t = t + t/2;
			if(t >= _old_delta_time)
			{
				t = _old_delta_time;
				findCollisionTime = true;
			}
			//find the colosed t to the time for collision happen
			//findCollisionTime = true;//jump out of loop
		}

	}

	float left_t = _old_delta_time - t;
	
	YPoint speed_collision;
	speed_collision.x = shapeA.old_velocity.x + shapeA.acceleration.x * t;
	speed_collision.y = shapeA.old_velocity.y + shapeA.acceleration.y * t;
	speed_collision.z = 0;
	//y  = -y
	speed_collision.y = -speed_collision.y;
	//get new movement
	tempmovement.x = float(speed_collision.x * left_t + 0.5 * shapeA.acceleration.x * left_t * left_t);
	tempmovement.y = float(speed_collision.y * left_t + 0.5 * shapeA.acceleration.y * left_t * left_t);
	tempmovement.z = 0.0f;

	//get end speed
	shapeA.velocity.x = speed_collision.x + shapeA.acceleration.x * left_t;
	shapeA.velocity.y = speed_collision.y + shapeA.acceleration.y * left_t;
	shapeA.velocity.z = 0;

	shapeA.Move(tempmovement);
	*/


	
	//cout<<"ground hit"<<endl;
	//test here
	//shapeA.velocity.Clear();
	//shapeA.Move(shapeA.penmove);
	//shapeA.force.y += (shapeA.mass*G_ACCERLATION*-1);

	//float allmy = shapeA.movement.y * -1 - shapeA.penmove.y;
	//cout<<allmy<<endl;

	
	float s_h = (shapeA.movement.y) - abs(shapeA.penmove.y);
	cout<<s_h<<endl;
	//YPoint downmovement;
	//downmovement.x = shapeA.movement.x - shapeA.penmove.x;
	//downmovement.y = shapeA.movement.y + shapeA.penmove.y;
	//downmovement.z = 0;


}

bool PhysicsThread::CollisionDectectShapeAndGround(Shape&shape,const Shape&ground)
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
	bool overlap = false;

	if(penAx>0)
	{
		overlap = true;	
	}
	else
	{
		overlap = false;
	}

	if(overlap)
	{
		//get penmove value
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
	}

	return false;
	
}

void PhysicsThread::FreeMoveShape(Shape&shape)
{
	float t = _delta_time/1000;//ms -> s
	///
	shape.old_force = shape.force;
	shape.acceleration.x = shape.force.x / shape.mass;
	shape.acceleration.y = shape.force.y / shape.mass + G_ACCERLATION;
	shape.force.Clear();
	///
	//YPoint movement;
	shape.old_movement = shape.movement;
	shape.movement.x = float(shape.velocity.x * t + 0.5 * shape.acceleration.x * t * t);
	shape.movement.y = float(shape.velocity.y * t + 0.5 * shape.acceleration.y * t * t);
	shape.movement.z = 0.0f;
	///
	shape.old_velocity = shape.velocity;
	shape.velocity.x = shape.velocity.x + shape.acceleration.x * t;
	shape.velocity.y = shape.velocity.y + shape.acceleration.y * t;
	//////////////////////////////////////////////////////////////////////////
	shape.Move(shape.movement);
	//shape.movement.Clear();

}

void PhysicsThread::ReduceDisMistake(float&dis)
{
	if(abs(dis) < NUM_RANGE_HIGH)
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

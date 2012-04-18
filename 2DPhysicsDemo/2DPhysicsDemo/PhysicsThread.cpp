#include "PhysicsThread.h"


PhysicsThread::PhysicsThread(void)
{
	_delta_time  = 0.0f;
	_isspringforcegenerated = false;

	ORIGIN_P_PHYSICS.x = 0;
	ORIGIN_P_PHYSICS.y = 0;

	measureP.x = -10;
	measureP.y = 0;
}


PhysicsThread::~PhysicsThread(void)
{
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
					CalculatePyhsics5();
					
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
	//change position
	int objnum = _shapeShareObject->renderObjects.size();
	if(_isspringforcegenerated)
	{
		
		for(int i = 0; i< objnum;i++)
		{
			Shape* shape = _shapeShareObject->renderObjects.at(i);

			vector<YPoint>& pa = shape->points;
			if(JudgePointInPologon(pa,_springforceworkposition,measureP))
			{
				cout<<"s in id = "<<shape->id<<"x = "<<_springforce.force_x<<"y = "<<_springforce.force_y<<endl;

				//add spring force
			}
		}
	}
	

	for(int i = 0; i< objnum;i++)
	{
		Shape* shape = _shapeShareObject->renderObjects.at(i);
		
		//change position by speed
		shape->middlepoint.x = 0;
		shape->middlepoint.y = 0;
		for(vector<YPoint>::iterator p = shape->points.begin();   
			p !=  shape->points.end();  
			p++)
		{
			p->x += shape->velocity.x;
			p->y += shape->velocity.y;


			shape->middlepoint.x += p->x;
			shape->middlepoint.y += p->y;
		}

		shape->middlepoint.x = shape->middlepoint.x / shape->points.size();
		shape->middlepoint.y = shape->middlepoint.y / shape->points.size();

		//checkground
		CheckHitGround(shape);
		
	}

	for(int i = 0; i <(objnum - 1);i++)
	{
		Shape* A = _shapeShareObject->renderObjects.at(i);
		
		for(int j = i+1; j < objnum; j++  )
		{
			Shape* B = _shapeShareObject->renderObjects.at(j);

			//CheckCollision(A,B);
		}

	}

}
void PhysicsThread::CheckCollision(Shape* shapeA, Shape* shapeB)
{
	float dx = shapeB->middlepoint.x - shapeA->middlepoint.x;
	float dy = shapeB->middlepoint.y - shapeA->middlepoint.y;
	float dist = sqrt(dx*dx + dy*dy);

	if(ProjectCollisionDetect2(*shapeA,*shapeB))
	{
		// 计算角度和正余弦值
		float angle = atan2(dy,dx);
		float sinv = sin(angle);
		float cosv = cos(angle);
		// 旋转 A 的位置 pos0
		shapeA->pos.x = 0.0f;
		shapeA->pos.y = 0.0f;
		//旋转 B 的位置 pos1
		Rotate(dx,dy,sinv,cosv,true,shapeB->pos);
		//
		YPoint velA;
		Rotate(shapeA->velocity.x,shapeA->velocity.y,sinv,cosv,true,velA);
		YPoint velB;
		Rotate(shapeB->velocity.x,shapeB->velocity.y,sinv,cosv,true,velB);
		//
		float vxTotal = velA.x - velB.x;
		velA.x = ((shapeA->mass - shapeB->mass)* velA.x + 2* shapeB->mass * velB.x)/(shapeA->mass + shapeB->mass);
		velB.x = vxTotal + velA.x;
		//*************************** overlap
		float absV = abs(velA.x)+abs(velB.x);
		float overlap = float((0.02) - abs(shapeA->pos.x - shapeB->pos.x));
		shapeA->pos.x += velA.x / absV * overlap;
		shapeB->pos.x += velB.x / absV * overlap;
		//
		YPoint posAF;
		Rotate(shapeA->pos.x, shapeA->pos.y, sinv,cosv,false,posAF);
		YPoint posBF;
		Rotate(shapeB->pos.x, shapeB->pos.y, sinv,cosv,false,posBF);
		//
		int asize = shapeA->points.size();
		for(int i = 0;i < asize; i++)
		{
			shapeA->points.at(i).x =  shapeA->points.at(i).x + posAF.x;
			shapeA->points.at(i).y =  shapeA->points.at(i).y + posAF.y;
		}
		shapeA->middlepoint.x = shapeA->middlepoint.x + posAF.x;
		shapeA->middlepoint.y = shapeA->middlepoint.y + posAF.y;

		int bsize = shapeB->points.size();
		for(int i = 0;i < bsize; i++)
		{
			shapeB->points.at(i).x =  shapeB->points.at(i).x + posBF.x;
			shapeB->points.at(i).y =  shapeB->points.at(i).y + posBF.y;
		}
		shapeB->middlepoint.x = shapeB->middlepoint.x + posBF.x;
		shapeB->middlepoint.y = shapeB->middlepoint.y + posBF.y;
		//
		YPoint velAF;
		Rotate(velA.x, velA.y, sinv, cosv, false, velAF);
		YPoint velBF;
		Rotate(velB.x, velB.y, sinv, cosv, false, velBF);
		shapeA->velocity.x = velAF.x;
		shapeA->velocity.y = velAF.y;
		shapeB->velocity.x = velBF.x;
		shapeB->velocity.y = velBF.y;

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

		
		shape->g = 0.0;
		
	}else
	{
		shape->g = 1.0;
	}

}

/**
void PhysicsThread::CalculatePyhsics4()
{
	//get ground before use 
	Shape* ground = _shapeShareObject->renderObjects.at(1);
	for(vector<Shape*>::iterator shapeAiterator = _shapeShareObject->renderObjects.begin();   
		shapeAiterator !=  _shapeShareObject->renderObjects.end();  
		shapeAiterator++)
	{
		Shape* shapeA = *shapeAiterator;
		if(shapeA->type>1)//shape must be common
		{
			for(vector<Shape*>::iterator shapeBiterator = _shapeShareObject->renderObjects.begin();   
				shapeBiterator !=  _shapeShareObject->renderObjects.end();  
				shapeBiterator++)
			{
				Shape* shapeB = *shapeBiterator;
				if(shapeB->type > 0 && shapeB->id != shapeA->id )
				{
					shapeA->hitsometing = true;
					//hit ground
					if(shapeB->type == 1)
					{
						shapeA->hitground = true;
						shapeA->cantransferpower = true;
						//do some response
						if(shapeA->velocity_y <= 0)
							shapeA->velocity_y = 0;
					}
					else
					{
						shapeA->hitground = false;
						shapeA->cantransferpower = false;
					}
					//hit common
					if(shapeB->type > 1)
					{
						//do some response





					}

				}

			}


		}
	}
}
//only think about the Y axix
void PhysicsThread::CalculatePyhsics3(){
	//get ground before use 
	Shape* ground = _shapeShareObject->renderObjects.at(1);
	//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	for(vector<Shape*>::iterator shapeAiterator = _shapeShareObject->renderObjects.begin();   
		shapeAiterator !=  _shapeShareObject->renderObjects.end();  
		shapeAiterator++)
	{
		//get shapeA
		Shape* shapeA = *shapeAiterator;
		if(shapeA->type>1)//shape must be common
		{

			//judge hit with ground ProjectCollisionDetect ProjectGroundCollisionDetect
			if(ProjectCollisionDetect2(*shapeA,*ground))
			{
				shapeA->cantransferpower = true;
				shapeA->hitground = true;
				shapeA->hitsometing = true;
				
			}
			else
			{
				
				shapeA->cantransferpower = false;
				shapeA->hitground = false;
				shapeA->hitsometing = false;
			}

			//judge hit common shape
			for(vector<Shape*>::iterator shapeBiterator = _shapeShareObject->renderObjects.begin();   
				shapeBiterator !=  _shapeShareObject->renderObjects.end();  
				shapeBiterator++)
			{
				Shape* shapeB = *shapeBiterator;
				if(shapeB->type > 1 && shapeB->id != shapeA->id )
				{
					
					if(ProjectCollisionDetect2(*shapeA,*shapeB))
					{
						shapeA->hitsometing = true;
						if(shapeB->hitground || shapeB->cantransferpower)
						{
							shapeA->cantransferpower = true;
						}

					}

				}

			}


			if(shapeA->hitground)
			{

				shapeA->r = 1.0;
				shapeA->g = 1,0;
				shapeA->b = 0.0;
			}
			else
			{
				shapeA->r = 1.0;
				shapeA->g = 0,0;
				shapeA->b = 0.0;
			}
			
		}

	}
	//////////////////////////////////////////////////////////////////////////
	//computing spring force
	if(_isspringforcegenerated)
	{
		for(vector<Shape*>::iterator shapeAiterator = _shapeShareObject->renderObjects.begin();   
			shapeAiterator !=  _shapeShareObject->renderObjects.end();  
			shapeAiterator++)
		{
			Shape* shapeA = *shapeAiterator;
			//get all points in the shape
			if(shapeA->type>1)
			{
				vector<YPoint>& pa = shapeA->points;
				if(JudgePointInPologon(pa,_springforceworkposition,ORIGIN_P_PHYSICS) && shapeA->cantransferpower)
				{
					cout<<"spring in "<<shapeA->id<<endl;
					//the force only work on static object
					shapeA->force_in_y = _springforce.force_y;
					shapeA->force_in_x = _springforce.force_x;
					
					/////////////////////////////////////////
					if(shapeA->force_in_y > 0)
						shapeA->force_in_dir_y = 1;
					if(shapeA->force_in_y == 0)
						shapeA->force_in_dir_y = 0;
					if(shapeA->force_in_y < 0)
						shapeA->force_in_dir_y = -1;
					/////////////////////////////////////////
					if(shapeA->force_in_x > 0)
						shapeA->force_in_dir_x = 1;
					if(shapeA->force_in_x == 0)
						shapeA->force_in_dir_x = 0;
					if(shapeA->force_in_x < 0)
						shapeA->force_in_dir_x = -1;
					////////////////////////////////////////
					
					break;
				}				

			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	//calculate force and a move
	const float ga = -0.000001f;
	for(vector<Shape*>::iterator shapeAiterator = _shapeShareObject->renderObjects.begin();   
		shapeAiterator !=  _shapeShareObject->renderObjects.end();  
		shapeAiterator++)
	{
		//get shape
		Shape* shapeA = *shapeAiterator;
		if(shapeA->type>1)
		{
			shapeA->force_all_x = shapeA->force_in_x;
			shapeA->force_in_x = 0;
			shapeA->force_all_y = shapeA->force_in_y + shapeA->mass * ga;
			shapeA->force_in_y = 0;

			//x a
			shapeA->acceleration_x = shapeA->force_all_x / shapeA->mass;
			shapeA->force_all_x = 0;

			//y a
			shapeA->acceleration_y = shapeA->force_all_y / shapeA->mass;
			shapeA->force_all_y = 0;


			//v x y
			shapeA->old_velocity_x = shapeA->velocity_x;
			shapeA->old_velocity_y = shapeA->velocity_y;

			shapeA->velocity_x = shapeA->old_velocity_x + shapeA->acceleration_x * _delta_time;
			shapeA->velocity_y = shapeA->old_velocity_y + shapeA->acceleration_y * _delta_time;

			float mx = float(shapeA->old_velocity_x * _delta_time + 0.5 * shapeA->acceleration_x * _delta_time * _delta_time);
			float my = float(shapeA->old_velocity_y * _delta_time + 0.5 * shapeA->acceleration_y * _delta_time * _delta_time);

			shapeA->acceleration_x = 0;
			shapeA->acceleration_y = 0;

			if(shapeA->hitsometing)
			{
				if(shapeA->hitground || shapeA->cantransferpower)
				{
					if(my<0)
					{
						my = 0;
						shapeA->velocity_y = 0;

						mx = 0;
						shapeA->velocity_x = 0;
					}
				}
				
				
			}

			//get all points in the shape
			vector<YPoint>& pa = shapeA->points;
			int size = pa.size();
			for(int i = 0; i< size; i++)
			{
				pa.at(i).x = pa.at(i).x + mx;
				pa.at(i).y = pa.at(i).y + my;
			}
			shapeA->middlepoint.y = shapeA->middlepoint.y + my;
			shapeA->middlepoint.x = shapeA->middlepoint.x + mx;

		}
	}
	
}
*/
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

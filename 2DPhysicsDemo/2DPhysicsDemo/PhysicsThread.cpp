#include "PhysicsThread.h"


PhysicsThread::PhysicsThread(void)
{
	_delta_time  = 0.0f;
	_isspringforcegenerated = false;
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
						float allforce = SPRING_FACTOR * _springforce.length;
						//get force direction
						_springforce.dir_x = _shapeShareObject->springendp.x - _shapeShareObject->springstartp.x;
						_springforce.dir_y = _shapeShareObject->springendp.y - _shapeShareObject->springstartp.y;
						//computing force x y
						float dd = sqrt(_springforce.dir_x * _springforce.dir_x + _springforce.dir_y * _springforce.dir_y);
						_springforce.force_x = _springforce.dir_x * allforce / dd;
						_springforce.force_y = _springforce.dir_y * allforce / dd;
						//save the position to a Point, easy to computing later
						_springforceworkposition.x = _shapeShareObject->springstartp.x;
						_springforceworkposition.y = _shapeShareObject->springstartp.y;
						/*cout<<"clear spring"<<endl;*/
						//after save the current spring variables, clear the variables in shareobject
						_shapeShareObject->springstartp.x = 0;
						_shapeShareObject->springstartp.y = 0;
						_shapeShareObject->springendp.x = 0;
						_shapeShareObject->springendp.y = 0;

						//mark
						_isspringforcegenerated = true;
					}
					else
					{
						_isspringforcegenerated = false;
					}
					//////////////////////////////////////////
					//start to compute the physics
					CalculatePyhsics3();
					
				}

			}__finally{
				_shapeShareObject->Release();
			}
		}



	}
	return 0;
}
void PhysicsThread::CalculatePyhsics3()
{

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
				/*cout<<"g"<<shapeA->id<<endl;*/
			}
			else
			{
				/*cout<<"g"<<shapeA->id<<endl;*/
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
	const float ga = -0.000001;
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

			float mx = shapeA->old_velocity_x * _delta_time + 0.5 * shapeA->acceleration_x * _delta_time * _delta_time;
			float my = shapeA->old_velocity_y * _delta_time + 0.5 * shapeA->acceleration_y * _delta_time * _delta_time;

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

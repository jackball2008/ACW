#include "PhysicsThread.h"


PhysicsThread::PhysicsThread(void)
{
	_delta_time  = 0.0f;

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
		Sleep(10);
		
		//
		if(_shapeShareObject->Acquire()){
			__try{
				//only get the access,then calculate the time _delta_time
				CalculateDeltaTime();
				if(_delta_time <10000 ){
					
					float springlength = Dis(_shapeShareObject->springstartp,_shapeShareObject->springendp);
					if(!_shapeShareObject->left_hold && springlength >0){

						_springforce.energy = SPRING_FACTOR * springlength;

						_springforce.dx = _shapeShareObject->springendp.x - _shapeShareObject->springstartp.x;
						_springforce.dy = _shapeShareObject->springendp.y - _shapeShareObject->springstartp.y;
						_springforce.sx = _shapeShareObject->springstartp.x;
						_springforce.sy = _shapeShareObject->springstartp.y;
						_checkp.x = _springforce.sx;
						_checkp.y = _springforce.sy;


						/*cout<<"clear spring"<<endl;*/
						_shapeShareObject->springstartp.x = 0;
						_shapeShareObject->springstartp.y = 0;
						_shapeShareObject->springendp.x = 0;
						_shapeShareObject->springendp.y = 0;
					}
					//////////////////////////////////////////
					//get one polygon to
					CalculatePyhsics();
						
					
				}

			}__finally{
				_shapeShareObject->Release();
			}
		}



	}
	return 0;
}

#define DEBUG_DELTATIME1
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

#define USINGMATHOD1
void PhysicsThread::CalculatePyhsics(){
	for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
		ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
		ite_vec_shape++)
	{
			Shape* shape = *ite_vec_shape;
			vector<Point>& pa = shape->points;
			//check the spring start point in or not in the shape's polygon
			if(shape->type >1)
			{
					
					float my = 0;
					float mx = 0;
					//type>1 = polygon now line or spring itself
					if(JudgePointInPologon(pa,_checkp,ORIGIN_P_PHYSICS)){
						//make spring work a = f/m
						shape->acceleration = _springforce.energy / (shape->mass * 1000);
						//_checkp reset
						_checkp.x = 20;
						_checkp.y = 20;
						//energy reset = 0;
						_springforce.energy = 0;
						//
						/*shape->becontrolled = true;*/
						
					}
					else{
						shape->acceleration = 0;
						/*shape->becontrolled = false;*/

					}

					if(/*shape->becontrolled &&*/ shape->acceleration != 0){
						//v = v + at
						shape->velocity = shape->velocity + shape->acceleration * _delta_time;
						//reset acceleration
						shape->acceleration = 0;

					}else{
						
					}
					//change position get s = v + 1/2 * a * t * t
					float distanceformove = float(shape->velocity + 0.5* shape->acceleration * _delta_time * _delta_time);
					//solve 1
#ifdef USINGMATHOD1
					float dd = sqrt(_springforce.dx * _springforce.dx + _springforce.dy * _springforce.dy);
					
					if(dd!=0){
						my =   distanceformove * _springforce.dy / dd;
						mx =   distanceformove * _springforce.dx / dd;
						
#else
					//solve 2
					float tanangle = _springforce.dx/_springforce.dy;
					float my = float(sqrt(distanceformove * distanceformove / ( 1+ tanangle * tanangle)));
					float mx = float(my * tanangle);
#endif
					}else{
						my = 0;
						mx = 0;
					}
					//update all points position
					int nsize = pa.size();
					for(int i=0; i<nsize;i++){
						pa.at(i).x = pa.at(i).x + mx;
						pa.at(i).y = pa.at(i).y + my;
					}
					//update middle points
					shape->middlepoint.x = shape->middlepoint.x + mx;
					shape->middlepoint.y = shape->middlepoint.y + my;
					//reset mx my
					mx = 0;
					my = 0;
					
				

			}




	}
}

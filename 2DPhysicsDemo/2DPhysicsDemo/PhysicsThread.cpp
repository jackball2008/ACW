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
					//get spring length
					float springlength = Dis(_shapeShareObject->springstartp,_shapeShareObject->springendp);
					_springforce.length = springlength;
					if(!_shapeShareObject->left_hold && _springforce.length >0){
						//get spring force
						_springforce.energy = SPRING_FACTOR * _springforce.length;
						//get force direction
						_springforce.dx = _shapeShareObject->springendp.x - _shapeShareObject->springstartp.x;
						_springforce.dy = _shapeShareObject->springendp.y - _shapeShareObject->springstartp.y;
						//get force effect point position
						_springforce.sx = _shapeShareObject->springstartp.x;
						_springforce.sy = _shapeShareObject->springstartp.y;
						//save the position to a Point, easy to computing later
						_checkp.x = _springforce.sx;
						_checkp.y = _springforce.sy;

						/*cout<<"clear spring"<<endl;*/
						//after save the current spring variables, clear the variables in shareobject
						_shapeShareObject->springstartp.x = 0;
						_shapeShareObject->springstartp.y = 0;
						_shapeShareObject->springendp.x = 0;
						_shapeShareObject->springendp.y = 0;
					}
					//////////////////////////////////////////
					//start to compute the physics
					CalculatePyhsics2();
					
				}

			}__finally{
				_shapeShareObject->Release();
			}
		}



	}
	return 0;
}

void PhysicsThread::CalculatePyhsics2(){
	for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
		ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
		ite_vec_shape++)
	{
		//get shape
		Shape* shape = *ite_vec_shape;
		//get all points in the shape
		vector<Point>& pa = shape->points;
		if(shape->type >1)
		{
			//computing the force
			if(JudgePointInPologon(pa,_checkp,ORIGIN_P_PHYSICS) && _springforce.length>0  )
			{
				//computing the push force
				shape->force =  _springforce.energy;
				//force direction
				shape->direction.x = _springforce.dx - shape->direction.x;
				shape->direction.y = _springforce.dy - shape->direction.y;
				float dd = sqrt(shape->direction.x * shape->direction.x + shape->direction.y * shape->direction.y);
				// ----
				shape->force_x = shape->direction.x * shape->force / dd;
				//fy - g  ||||
				shape->force_y = (shape->direction.y * shape->force / dd);
				//////////////////////////////////////////////////////////////////////////
				//G = m*g
				shape->force_y = shape->force_y /*+ shape->mass * G_ACCERLATION*/;
				//////////////////////////////////////////////////////////////////////////
				//the initialize force only work once, then clear
				//_checkp reset
				_checkp.x = 0;
				_checkp.y = 0;
				//energy reset = 0;
				_springforce.energy = 0;
				_springforce.length = 0;
				//direction reset
				_springforce.dx = 0;
				_springforce.dy = 0;
				//////////////////////////////////////////////////////////////////////////
			}
			else
			{
				//no spring force
				shape->force_x = 0;
				//fy = m * g
				//shape->force_y = shape->mass * G_ACCERLATION;

			}

			//computing the accerlation

			shape->acceleration_x = shape->force_x / shape->mass;
			shape->acceleration_y = shape->force_y / shape->mass;
			shape->force_x = 0;
			shape->force_y = 0;
			//computing the speed
			shape->old_velocity_x = shape->velocity_x;
			shape->old_velocity_y = shape->velocity_y;
			shape->velocity_x = shape->velocity_x + shape->acceleration_x * _delta_time;
			shape->velocity_y = shape->velocity_y + shape->acceleration_y * _delta_time;
			if(shape->velocity_y != 0)
			{
				float k = 0;
			}
			
			//computing the dis
			float mx = float(shape->old_velocity_x * _delta_time + 0.5 * shape->acceleration_x * _delta_time * _delta_time);
			float my = float(shape->old_velocity_y * _delta_time + 0.5 * shape->acceleration_y * _delta_time * _delta_time);

			//update shape position
			int nsize = pa.size();
			
			for(int i=0; i<nsize;i++){
				
				pa.at(i).x = pa.at(i).x + mx;
				//////////////////////////////////////////////////////////////////////////
				float y = pa.at(i).y + my;
				if(y < GROUND_Y)
					y = 0;
				else
					pa.at(i).y = pa.at(i).y + my;

				//////////////////////////////////////////////////////////////////////////
			}
			//update middle points
			shape->middlepoint.x = shape->middlepoint.x + mx;
			float middley = shape->middlepoint.y + my;
			if (middley < GROUND_Y)
			{

			} 
			else
			{
				shape->middlepoint.y = shape->middlepoint.y + my;
			}
			





		}

	}
}

void PhysicsThread::CalculatePyhsics(){
	//pass each shape
	for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
		ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
		ite_vec_shape++)
	{
			//get shape
			Shape* shape = *ite_vec_shape;
			//get all points in the shape
			vector<Point>& pa = shape->points;
			//check the spring start point in or not in the shape's polygon
			if(shape->type >1)
			{
					
				float my = 0;
				float mx = 0;
				//type>1 = polygon now line or spring itself
				if(JudgePointInPologon(pa,_checkp,ORIGIN_P_PHYSICS) && _springforce.length>0  ){
					//compute G and F
					//make spring work a = f/m
					shape->acceleration = _springforce.energy / (shape->mass);
					//change direction
					shape->direction.x = _springforce.dx - shape->direction.x;
					shape->direction.y = _springforce.dy - shape->direction.y;
					//_checkp reset
					_checkp.x = 0;
					_checkp.y = 0;
					//energy reset = 0;
					_springforce.energy = 0;
					_springforce.length = 0;
					//direction reset
					_springforce.dx = 0;
					_springforce.dy = 0;
						
					
				}else{
					//only compute G


				}
				

				if(shape->acceleration != 0){
					//v = v + at  get new velocity
					shape->velocity = shape->velocity + shape->acceleration * _delta_time;
					//reset acceleration
					shape->acceleration = 0;

				}
				//change position get s = v * t + 1/2 * a * t * t
				float distanceformove = float(shape->velocity * _delta_time  + 0.5* shape->acceleration * _delta_time * _delta_time);
				//solve 1

				float dd = sqrt(shape->direction.x * shape->direction.x + shape->direction.y * shape->direction.y);
					
				if(dd!=0){
					my =   distanceformove * shape->direction.y / dd;
					mx =   distanceformove * shape->direction.x / dd;
						
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



			}




	}
}


//////////////////////////////////////////////////////////////////////////
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

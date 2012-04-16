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
/**
void PhysicsThread::CalculatePyhsics2(){
	for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
		ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
		ite_vec_shape++)
	{
		//get shape
		Shape* shape = *ite_vec_shape;
		//get all points in the shape
		vector<YPoint>& pa = shape->points;
		if(shape->type >1)
		{
			bool ispushforceony = false;
			//computing the force
			if(JudgePointInPologon(pa,_springforceworkposition,ORIGIN_P_PHYSICS) && _springforce.length>0  )
			{
				//computing the push force
				shape->force =  SPRING_FACTOR * _springforce.length;
				//force direction
				shape->direction.x = _springforce.dir_x - shape->direction.x;
				shape->direction.y = _springforce.dir_y - shape->direction.y;
				float dd = sqrt(shape->direction.x * shape->direction.x + shape->direction.y * shape->direction.y);
				//x force
				shape->work_force_x = shape->direction.x * shape->force / dd;
				//fy - g  ||||
				shape->work_force_y = shape->direction.y * shape->force / dd;
				shape->work_force_y = shape->work_force_y + shape->mass * G_ACCERLATION;
				//////////////////////////////////////////////////////////////////////////
				//the initialize force only work once, then clear
				//_checkp reset
				_springforceworkposition.x = 0;
				_springforceworkposition.y = 0;
				//allforce reset = 0;
				_springforce.allforce = 0;
				_springforce.length = 0;
				//direction reset
				_springforce.dir_x = 0;
				_springforce.dir_y = 0;
				//////////////////////////////////////////////////////////////////////////
			}
			else
			{
				//no spring force
				shape->work_force_x = 0;
				//fy = m * g
				shape->work_force_y = shape->work_force_y + shape->mass * G_ACCERLATION; 
				
			}

			//computing the accerlation
			shape->acceleration_x = shape->work_force_x / shape->mass;
			shape->acceleration_y = shape->work_force_y / shape->mass;
			//clear force
			shape->work_force_x = 0;
			shape->work_force_y = 0;
			//computing the speed
			shape->old_velocity_x = shape->velocity_x;
			shape->old_velocity_y = shape->velocity_y;
			shape->velocity_x = shape->velocity_x + shape->acceleration_x * _delta_time;
			shape->velocity_y = shape->velocity_y + shape->acceleration_y * _delta_time;			
			//computing the dis
			float mx = float(shape->old_velocity_x * _delta_time + 0.5 * shape->acceleration_x * _delta_time * _delta_time);
			float my = float(shape->old_velocity_y * _delta_time + 0.5 * shape->acceleration_y * _delta_time * _delta_time);
			//update shape position
			int nsize = pa.size();
			float middlep_x = 0;
			float midllep_y = 0;
			for(int i=0; i<nsize;i++){
				pa.at(i).x = pa.at(i).x + mx;
				middlep_x = middlep_x + pa.at(i).x;
				pa.at(i).y = pa.at(i).y + my;
				midllep_y = midllep_y + pa.at(i).y;
			}
			//update middle points
			shape->middlepoint.x = middlep_x / nsize;
			shape->middlepoint.y = midllep_y / nsize;
			cout<<"x = "<<shape->middlepoint.x<<" y = "<<shape->middlepoint.y<<endl;
			//////////////////////////////////////////////////////////////////////////
			//do collection detection
			//test hit ground first
			Shape* groundline = _shapeShareObject->renderObjects.at(1);
			if(DectecHit(*shape,*groundline))
			{
				shape->work_force_y = -(shape->mass * G_ACCERLATION);

			}
			//test hit other shapes
			
			for(vector<Shape*>::iterator ite_vec_shape1 = _shapeShareObject->renderObjects.begin();   
				ite_vec_shape1 !=  _shapeShareObject->renderObjects.end();  
				ite_vec_shape1++)
			{
				//get shape
				Shape* dshape = *ite_vec_shape;
				
				if(dshape->type>1)// not spring and groundline
				{
					if(shape->id != dshape->id && DectecHit(*shape,*dshape))
						cout<<"hit"<<endl;
					
				}
			}
			
			

		}

	}
}
*/
/**
bool PhysicsThread::DectecHit(const Shape&s1, const Shape& s2){

	bool res = false;
	int s1size = s1.points.size();
	int s2size = s2.points.size();
	//JudgeTwoLineAcroess
	for(int i=0; i<s1size;i++){
		
		for (int j = 0; j < s2size; j++)
		{
			if((i+1)<s1size)
			{
				if((j+1)<s2size)
					res = JudgeTwoLineAcroess(s1.points.at(i),s1.points.at(i+1),s2.points.at(j),s2.points.at(j+1));
				else
					res = JudgeTwoLineAcroess(s1.points.at(i),s1.points.at(i+1),s2.points.at(j),s2.points.at(0));
			}
			else
			{
				if((j+1)<s2size)
					res = JudgeTwoLineAcroess(s1.points.at(i),s1.points.at(0),s2.points.at(j),s2.points.at(j+1));
				else
					res = JudgeTwoLineAcroess(s1.points.at(i),s1.points.at(0),s2.points.at(j),s2.points.at(0));

			}
			
			if(res)
				return res;

		}


	}
	return false;
}
*/
/*
void PhysicsThread::CalculatePyhsics(){
	//pass each shape
	for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
		ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
		ite_vec_shape++)
	{
			//get shape
			Shape* shape = *ite_vec_shape;
			//get all points in the shape
			vector<YPoint>& pa = shape->points;
			//check the spring start point in or not in the shape's polygon
			if(shape->type >1)
			{
					
				float my = 0;
				float mx = 0;
				//type>1 = polygon now line or spring itself
				if(JudgePointInPologon(pa,_springforceworkposition,ORIGIN_P_PHYSICS) && _springforce.length>0  ){
					//compute G and F
					//make spring work a = f/m
					shape->acceleration = _springforce.allforce / (shape->mass);
					//change direction
					shape->direction.x = _springforce.dir_x - shape->direction.x;
					shape->direction.y = _springforce.dir_y - shape->direction.y;
					//_checkp reset
					_springforceworkposition.x = 0;
					_springforceworkposition.y = 0;
					//energy reset = 0;
					_springforce.allforce = 0;
					_springforce.length = 0;
					//direction reset
					_springforce.dir_x = 0;
					_springforce.dir_y = 0;
						
					
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
*/

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

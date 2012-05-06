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

// 	cout << "The quiet NaN for type float is:  "
// 		<< numeric_limits<float>::quiet_NaN( )
// 		<< endl;
// 	cout << "The quiet NaN for type int is:  "
// 		<< numeric_limits<int>::quiet_NaN( )
// 		<< endl;
// 	cout << "The quiet NaN for type long double is:  "
// 		<< numeric_limits<long double>::quiet_NaN( )
// 		<< endl;


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




void PhysicsThread::CalculatePyhsics()
{
	//A is host b is guest
	int objnum = _shapeShareObject->renderObjects.size();
	for(int i=0;i<objnum;i++)
	{
		Shape* shapeA = _shapeShareObject->renderObjects.at(i);
		if (shapeA->type != 1)
		{
			//make sure A is not ground

			//do collision detect and response
			for(int j = 0; j<objnum;j++)
			{
				Shape* shapeB = _shapeShareObject->renderObjects.at(j);
				//shapeB maybe ground
				if(shapeA->id != shapeB->id)
				{
					/************************************************************************/
					/* do collision detect and response, and free down movement                                                                    */
					/************************************************************************/
					CollisionDectect(*shapeA,*shapeB);
				}
				else
				{
					continue;
				}

			}

			//do free move
			FreeMoveShape(*shapeA);

		}
		else
		{
			continue;
		}
		
	}
}
#define METHOD
#define NEWLOGIC
void PhysicsThread::CollisionDectect(Shape& shapeA, Shape& shapeB)
{

#ifdef NEWLOGIC
	if(shapeB.type != 1)
	{
		//shapeA hit common shape
		/***/
		if(CollisionDectectShapeAndShape(shapeA,shapeB))
		{
			ResponseCollisionWithShape(shapeA,shapeB);
		}
		
		
	}
	else
	{
		//shapeB is ground
		if(CollisionDectectShapeAndGround(shapeA))
		{
			ResponseCollisionWithGround(shapeA);
		}
	}

#endif

#ifdef METHOD1

	
	bool iscollision = false;

	if(shapeB.type != 1)
	{
		//shapeA hit common shape
		iscollision = CollisionDectectShapeAndShape(shapeA,shapeB);
	}
	else
	{
		//shapeB is ground
		iscollision = CollisionDectectShapeAndGround(shapeA);
	}
	
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
			ResponseCollisionWithGround(shapeA);
		}
	}
	else
	{
		//continue to work, free down
		FreeMoveShape(shapeA);
	}
	
#endif

#ifdef METHOD2

	
	if(shapeB.type != 1)
	{
		//shapeA hit common shape
		/***/
		if(CollisionDectectShapeAndShape(shapeA,shapeB))
		{
			ResponseCollisionWithShape(shapeA,shapeB);
		}
		else
		{
			FreeMoveShape(shapeA);
		}
		
	}
	else
	{
		//shapeB is ground
		if(CollisionDectectShapeAndGround(shapeA))
		{
			ResponseCollisionWithGround(shapeA);
		}
		else
		{
			FreeMoveShape(shapeA);
		}
	}
#endif
}

//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* collision detect with common shape                                                                     */
/************************************************************************/
bool PhysicsThread::CollisionDectectShapeAndShape(Shape&shapeA,Shape&shapeB)
{
	bool iscollision = false;

	int numofaxisA = shapeA.project_axis.size();
	int numofaxisB = shapeB.project_axis.size();
	//
	//fix function, get delta
	float deltax = shapeA.pos.x - shapeB.pos.x;
	float deltay = shapeA.pos.y - shapeB.pos.y;


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
		ReduceDisMistake(penAx,OVERLAP_MIN);
		//////////////////////////////////////////////////////////////////////////
		if(penAx>0)
		{
			//over lap
			iscollision = true;
		}
		else
		{
			//iscollision = false;
			return false;
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
			ReduceDisMistake(penAx,OVERLAP_MIN);
			//////////////////////////////////////////////////////////////////////////
			if(penAx>0)
			{
				//over lap on shapeB's axis
				//iscollision = true;
			}
			else
			{
// 				iscollision = false;
// 				break;
				return false;
			}

		}
	}

	return true;

}
/************************************************************************/
/* do collision response with common shape                                                                     */
/************************************************************************/
void PhysicsThread::ResponseCollisionWithShape(Shape&shapeA,Shape&shapeB)
{
	//cout<<"common hit"<<endl;
	//velocity  +/-
	/**
	float ax = 2*shapeB.mass*shapeB.velocity.x/(shapeA.mass + shapeB.mass);
	float ay = 2*shapeB.mass*shapeB.velocity.y/(shapeA.mass + shapeB.mass);
	
	float bx = 2*shapeA.mass*shapeA.velocity.x/(shapeA.mass + shapeB.mass);
	float by = 2*shapeA.mass*shapeA.velocity.y/(shapeA.mass + shapeB.mass);
	//velocity after collision

	ReduceDisMistake(ax,0.0001f);
	ReduceDisMistake(ay,0.0001f);
	ReduceDisMistake(bx,0.0001f);
	ReduceDisMistake(by,0.0001f);

	
	shapeA.velocity.x = ax;
	shapeA.velocity.y = ay;

	shapeB.velocity.x = bx;
	shapeB.velocity.y = by;
	
	
	float dir = ax*bx + ay*by;
	//float dir = shapeA.velocity.x*shapeB.velocity.x + shapeA.velocity.y * shapeB.velocity.y;
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
	*/
	//get num of axis, because only x,y axis used here,so the shapeA axis not useful here
	//int numofaxisA = shapeA.project_axis.size();

	//fix function, get delta
	float delta_x = shapeA.pos.x - shapeB.pos.x;
	float delta_y = shapeA.pos.y - shapeB.pos.y;

	//get the size in Y,because A and B is Collision, so ,they are must be overlap on Y and X axis

	//shapeA Y axis  (0,1)
	float A_size_y = 0;
	ProjectShape(A_size_y,shapeA,0,1);
	//shapeA X axis (1,0)
	float A_size_x = 0;
	ProjectShape(A_size_x,shapeA,1,0);
	//shapeB Y axis (0,1)
	float B_size_y = 0;
	ProjectShape(B_size_y,shapeB,0,1);
	//shapeB X axis (1,0)
	float B_size_x = 0;
	ProjectShape(B_size_x,shapeB,1,0);

// 	//get A value
// 	float A_high = shapeA.pos.y + A_size_y;
// 	float A_low	 = shapeA.pos.y - A_size_y;
// 	float A_right = shapeA.pos.x + A_size_x;
// 	float A_left = shapeA.pos.x - A_size_x;
// 
// 	//get B value
// 	float B_high = shapeB.pos.y + B_size_y;
// 	float B_low = shapeB.pos.y - B_size_y;
// 	float B_right = shapeB.pos.y + B_size_x;
// 	float B_left = shapeB.pos.x - B_size_x;



	//overlap value on X axis  *100/100 avoid IND
	float overlap_x = (A_size_x*100 + B_size_x*100 - abs(delta_x)*100)/100;
	//overlap value on Y axis
	float overlap_y = (A_size_y*100 + B_size_y*100 - abs(delta_y)*100)/100;
	//reduce overlap if overlap < 0.005f, overlap = 0
	//cout<<overlap_x<<"  "<<overlap_y<<endl;
	//////////////////////////////////////////////////////////
	ReduceDisMistake(overlap_x,OVERLAP_MIN);
	ReduceDisMistake(overlap_y,OVERLAP_MIN);
	//////////////////////////////////////////////////////////
// 	bool moveonX = false;
// 	bool moveonY = false;
// 
// 	if(overlap_x>0) moveonX = true;
// 	if(overlap_y>0) moveonY = true;

	float ax = 2*shapeB.mass*shapeB.velocity.x/(shapeA.mass + shapeB.mass);
	float ay = 2*shapeB.mass*shapeB.velocity.y/(shapeA.mass + shapeB.mass);

	float bx = 2*shapeA.mass*shapeA.velocity.x/(shapeA.mass + shapeB.mass);
	float by = 2*shapeA.mass*shapeA.velocity.y/(shapeA.mass + shapeB.mass);

	ReduceDisMistake(ax,SPEED_RESCRIT);
	ReduceDisMistake(ay,SPEED_RESCRIT);
	ReduceDisMistake(bx,SPEED_RESCRIT);
	ReduceDisMistake(by,SPEED_RESCRIT);

	
	shapeA.movement.Clear();

	if((overlap_y>0) && (overlap_y<overlap_x))
	{
		//do y
		if(shapeA.pos.y>shapeB.pos.y)
		{
			if(ay!=0)
				shapeA.velocity.y = ay;
			if(by!=0)
				shapeB.velocity.y = by;
			
			shapeA.movement.y = overlap_y;

		}
		else
		{
			shapeA.movement.y = 0;
		}
	}
	else
	{
		
		if(overlap_x>0)
		{
			//do x
			if(shapeA.pos.x>shapeB.pos.x)
			{
				if(ax!=0)
					shapeA.velocity.x = ax;

				if(bx!=0)
					shapeB.velocity.x = bx;

				shapeA.movement.x = overlap_x;
			}
			else
			{
				shapeA.movement.x = 0;
			}

		}
		
	}
	shapeA.Move(shapeA.movement);
	shapeA.movement.Clear();


	/**
	if(overlap_y<overlap_x)
	{
		//move on Y axis
		if(overlap_y>0)//because shapeA and shapeB collision, so they are overlap at any axises
		{
			
			//judge who is at higher position
			if(shapeA.pos.y > shapeB.pos.y)
			{
				//shapeA high
				shapeA.penmove.x = 0;
				shapeA.penmove.y = overlap_y;
				shapeA.Move(shapeA.penmove);
				shapeA.velocity.y = 0;
				//shapeA.velocity.Clear();
				//shapeA + up G
				//shapeA.force.y = 0;
				//shapeA.force.y = shapeA.mass*G_ACCERLATION*-1;

			}
			
		}
		else
		{
			
		}
		
	}
	else
	{
		//even if overlapx == overlapy, only move on X axis
		//move on X axis
		if(overlap_x>0)
		{

		}
		else
		{
			//past together on X axis
		}
	}
	*/
}

//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* collision detect with ground                                                                     */
/************************************************************************/
#define DEBUGV1
bool PhysicsThread::CollisionDectectShapeAndGround(Shape&shape)
{
	
	float asize = 0;
	ProjectShape(asize,shape,0,1);
	
	float low_point_y = shape.pos.y - asize;

	if(low_point_y*100 < GROUND_Y*100)
	{
		shape.penmove.y = (GROUND_Y*100 - low_point_y*100)/100;
#ifdef DEBUGV
		cout<<"++ "<<shape.penmove.y<<endl;
#endif
		return true;
	}
	else
	{
#ifdef DEBUGV
		cout<<"-- "<<shape.penmove.y<<"  "<<shape.pos.y<<endl;
#endif
		return false;
	}
}
/************************************************************************/
/* do collision response with ground                                                                     */
/************************************************************************/
void PhysicsThread::ResponseCollisionWithGround(Shape&shapeA)
{
	//pull back to the ground surface
	shapeA.Move(shapeA.penmove);
	//clear speed, because the speed is changed
	shapeA.velocity.y = 0;//only clear velocity on Y axis
	//give it a opposite force
	//shapeA.force.y += shapeA.mass * G_ACCERLATION * -1;
	//get the dis between start position and the hit position
	float blankdis = ((abs(abs(shapeA.movement.y))*100-(abs(shapeA.penmove.y)))*100)/100;
	//cout<<"++ "<<blankdis<<"  "<<shapeA.pos.y<<endl;
	//reduce the dis to save computing
	ReduceDisMistake(blankdis,OVERLAP_MIN);
	//do the bound operation
	if(blankdis!=0)
	{
		float v_g = 0;
		float t_g = 0;
		float t_left = 0;
		//this blankdis is big, need do some thing
		//v2 = sqrt(2gh + v1*v1); mgh+0.5mvv = 0.5mvv;
		v_g = sqrt(2*G_ACCERLATION*blankdis + shapeA.old_velocity.y * shapeA.old_velocity.y);
		//v2 = v1+gt  t_g < 0
		t_g = (v_g - abs(shapeA.old_velocity.y))/(abs(G_ACCERLATION));


		float tc = (_old_delta_time/1000)*1000 - t_g*1000;
		if(tc<10) tc = 0;
		t_left = tc/1000;//ms/1000->s

		//cout<<"-- "<<t_left<<"  "<<shapeA.pos.y<<endl;
		//
		shapeA.velocity.y = v_g * FANTAN_XISHU;

		shapeA.force.x = shapeA.force.x;
		//shapeA.force.y += shapeA.mass* G_ACCERLATION;

		if( shapeA.force.x == 0)
		{
			shapeA.acceleration.x = 0;
		}
		else
		{
			shapeA.acceleration.x = shapeA.force.x / shapeA.mass;
		}
// 		if( shapeA.force.y == 0)
// 		{
// 			shapeA.acceleration.y = 0;
// 		}
// 		else
// 		{
// 			shapeA.acceleration.y = shapeA.force.y / shapeA.mass;
// 		}
		shapeA.acceleration.y = 0;

		shapeA.movement.x = float(shapeA.velocity.x * t_left + 0.5 * shapeA.acceleration.x * t_left * t_left);
		shapeA.movement.y = float(shapeA.velocity.y * t_left + 0.5 * shapeA.acceleration.y * t_left * t_left);
		shapeA.Move(shapeA.movement);
	}
	else
	{
		//don't do bound operation
		shapeA.force.y = 0;
		shapeA.movement.y = 0;
		shapeA.velocity.y = 0;
	}

	//clear force
	shapeA.force.Clear();
	shapeA.movement.Clear();
}



void PhysicsThread::FreeMoveShape(Shape&shape)
{
	float t = _delta_time/1000;//ms -> s
	///
	//force x = 0; y = G*mass
	shape.old_force = shape.force;
	//x = x or change
	shape.force.y = shape.mass * G_ACCERLATION;

	shape.acceleration.x = shape.force.x / shape.mass;//wrong,only friction work here
	shape.acceleration.y = G_ACCERLATION;
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
	shape.movement.Clear();
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
void PhysicsThread::ReduceDisMistake(double&dis,const float&range)
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
					CalculatePyhsics();
					
				}

			}__finally{
				_shapeShareObject->Release();
			}
		}

	}
	return 0;
}

/************************************************************************/
/* static functions                                                                     */
/************************************************************************/
float PhysicsThread::Dis(const YPoint& p1, const YPoint& p2){
	float dx = p1.x - p2.x;
	float dy = p1.y - p2.y;
	float dz = p1.z - p2.z;
	return sqrt(dx*dx+dy*dy+dz*dz);
};

bool PhysicsThread::JudgePointInPologon(const vector<YPoint>& pa,const YPoint& mp,const YPoint& ori){
	int numofacroess = 0;
	int nsize = pa.size();
	for(int i=0; i<nsize;i++){
		if((i+1)<nsize){
			if(JudgeTwoLineAcroess(ori,mp,pa.at(i),pa.at(i+1)))
				numofacroess++;
		}else{
			if(JudgeTwoLineAcroess(ori,mp,pa.at(i),pa.at(0)))
				numofacroess++;
		}
	}
	if(!(numofacroess%2==0))
		return true;
	else
		return false;
}

bool PhysicsThread::JudgeTwoLineAcroess(const YPoint&L1p1, const YPoint&L1p2,const YPoint&L2p1, const YPoint&L2p2){
	float v1 = (L1p2.x - L1p1.x)*(L2p2.y-L1p1.y) - (L1p2.y-L1p1.y)*(L2p2.x-L1p1.x);
	float v2 = (L1p2.x-L1p1.x)*(L2p1.y-L1p1.y)-(L1p2.y-L1p1.y)*(L2p1.x-L1p1.x);
	if(v1*v2 >= 0) { 
		return false; 
	}
	float v3 = (L2p2.x-L2p1.x)*(L1p2.y-L2p1.y)-(L2p2.y-L2p1.y)*(L1p2.x-L2p1.x);
	float v4 = (L2p2.x-L2p1.x)*(L1p1.y-L2p1.y)-(L2p2.y-L2p1.y)*(L1p1.x-L2p1.x);
	if(v3*v4 >= 0) { 
		return false; 
	} 
	return true; 
}
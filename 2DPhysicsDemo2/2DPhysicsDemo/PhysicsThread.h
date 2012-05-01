#pragma once
#include "mythread.h"
#include <iostream>
/*#include <math.h>*/
#include "ShapeShareObject.h"
using namespace std;
#include <Windows.h>
#include "Force.h"


const float SPRING_FACTOR = 2.5f/100000;
const YPoint ORIGIN_P_PHYSICS;
///////////////////////////////////////////////
const float GROUND_Y = -0.9f;
const float NUM_RANGE_HIGH = 0.0000001f;
//const float NUM_RANGE_LOW = -0.000000001f;
const float G_ACCERLATION = -9.8f/10;
//const float EDGE_WIDTH = 0.0001f;

class PhysicsThread :
	public MyThread
{
private:
	//share obj store all share data
	ShapeShareObject* _shapeShareObject;
	YPoint measureP;
	//used for calculate deltatime
	DWORD procMask, sysMask;
	LARGE_INTEGER _ticksPerSecond, _consumedCount, _currentCount, _lastCount;
	//ms
	float _delta_time;
	float _old_delta_time;
	//thread
	HANDLE thread;

	//Force
	Force _springforce;
	YPoint _springforceworkposition;
	bool _isspringforcegenerated;

	//functions
	void CalculateDeltaTime();
	/**
	special functions
	*/


	//////////////////////////////////////////////////////////////////////////
	void CalculatePyhsics7();
	void ProjectShape(float&bsize, const Shape& shape, const float&ax,const float&ay);
	void CollisionDectect(Shape&, const Shape&);
	void ReduceDisMistake(float&dis);
	void FreeMoveShape(Shape&shape);
	bool CollisionDectectShapeAndGround(Shape&shape);
	void ResponseCollisionWithShape(Shape&shapeA,const Shape&shapeB);
	void ResponseCollisionWithGround(Shape&shapeA, const Shape&ground);
	//////////////////////////////////////////////////////////////////////////


public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };

	
	

	int run();

	static float Dis(const YPoint& p1, const YPoint& p2){
		float dx = p1.x - p2.x;
		float dy = p1.y - p2.y;
		float dz = p1.z - p2.z;
		return sqrt(dx*dx+dy*dy+dz*dz);
	};

	
	static bool JudgePointInPologon(const vector<YPoint>& pa,const YPoint& mp,const YPoint& ori){
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

	static bool JudgeTwoLineAcroess(const YPoint&L1p1, const YPoint&L1p2,const YPoint&L2p1, const YPoint&L2p2){
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

	

	

};


#pragma once
#include "mythread.h"
#include <iostream>
/*#include <math.h>*/
#include "ShapeShareObject.h"
using namespace std;
#include <Windows.h>
#include "Force.h"
#include <limits>

using namespace std;

const float SPRING_FACTOR = 2.5f/100000;
const YPoint ORIGIN_P_PHYSICS;
///////////////////////////////////////////////
const float GROUND_Y = -0.9f;
const float NUM_RANGE_HIGH = 0.0000001f;
const float G_ACCERLATION = -9.8f/100;
const float FANTAN_XISHU = 0.25f;
const float OVERLAP_MIN = 0.0001f;
const float OVERLAP_MIN2 = 0.002f;


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
	void CalculatePyhsics();
	void ProjectShape(float&bsize, const Shape& shape, const float&ax,const float&ay);
	void CollisionDectect(Shape&, Shape&);
	
	//collision with shape
	bool CollisionDectectShapeAndShape(Shape&shapeA,Shape&shapeB);
	void ResponseCollisionWithShape(Shape&shapeA,Shape&shapeB);
	//collision with ground
	bool CollisionDectectShapeAndGround(Shape&shape);
	void ResponseCollisionWithGround(Shape&shapeA);

	void FreeMoveShape(Shape&shape);

	void ReduceDisMistake(float&dis);
	void ReduceDisMistake(float&dis,const float&range);
	void ReduceDisMistake(double&dis,const float&range);
	//////////////////////////////////////////////////////////////////////////

public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };


	int run();
	/**
	static functions
	*/
 	static float Dis(const YPoint& p1, const YPoint& p2);	
	static bool JudgePointInPologon(const vector<YPoint>& pa,const YPoint& mp,const YPoint& ori);
	static bool JudgeTwoLineAcroess(const YPoint&L1p1, const YPoint&L1p2,const YPoint&L2p1, const YPoint&L2p2);

};


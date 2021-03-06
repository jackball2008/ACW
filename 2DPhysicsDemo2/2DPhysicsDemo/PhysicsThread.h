#pragma once
#include "mythread.h"
#include <iostream>
#include "ShapeShareObject.h"


using namespace std;


const float SPRING_FACTOR = 5.0f;
const YPoint ORIGIN_P_PHYSICS;
///////////////////////////////////////////////
const float GROUND_Y = -0.9f;
const float NUM_RANGE_HIGH = 0.0000001f;
const float G_ACCERLATION = -9.8f/100;
const float FANTAN_XISHU = 0.25f;
const float OVERLAP_MIN = 0.0001f;
const float OVERLAP_MIN2 = 0.002f;
const float SPEED_RESCRIT = 0.0001f;

const float HORIZONTAL_FROCTION_FACTOR = 0.995f;


class PhysicsThread :
	public MyThread
{
private:
	//share obj store all share data
	ShapeShareObject* _shapeShareObject;
	//used for calculate deltatime
	DWORD procMask, sysMask;
	LARGE_INTEGER _ticksPerSecond, _consumedCount, _currentCount, _lastCount;
	//ms
	float _delta_time;
	float _old_delta_time;
	//thread
	HANDLE thread;
	

	bool shapelocked;

	//functions
	void CalculateDeltaTime();
	/**
	special functions
	*/
	//////////////////////////////////////////////////////////////////////////
	void CalculatePyhsics();
	/************************************************************************/
	/* step one                                                                     */
	/************************************************************************/
	void CollisionDectect(Shape&, Shape&);

	/************************************************************************/
	/* step two                                                                     */
	/************************************************************************/
	//spring operation
	void SpringOperation(Shape&shape);
	/************************************************************************/
	/* step three                                                                     */
	/************************************************************************/
	//free down to the ground
	void FreeMoveShape(Shape&shape);


	/************************************************************************/
	/* used in step one                                                                     */
	/************************************************************************/
	//collision with shape
	bool CollisionDetectShapeAndShape(Shape&shapeA,Shape&shapeB);
	void ResponseCollisionWithShape(Shape&shapeA,Shape&shapeB);
	//collision with ground
	bool CollisionDetectShapeAndGround(Shape&shape);
	void ResponseCollisionWithGround(Shape&shapeA);

	/************************************************************************/
	/* used in step two                                                                     */
	/************************************************************************/
	//detect spring in or not in a shape
	bool DetectPointInShape(const Shape&shape,const float&x,const float&y);

	/************************************************************************/
	/* used in step three                                                                     */
	/************************************************************************/
	
	/************************************************************************/
	/* share functions                                                                     */
	/************************************************************************/
	//function project shape to a axis
	void ProjectShape(float&bsize, const Shape& shape, const float&ax,const float&ay);
	void ReduceDisMistake(float&dis);
	void ReduceDisMistake(float&dis,const float&range);
	void ReduceDisMistake(double&dis,const float&range);
	//////////////////////////////////////////////////////////////////////////

public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };


	int run();
	

};


#pragma once
#include "mythread.h"
#include <iostream>
#include <math.h>
#include "ShapeShareObject.h"
using namespace std;
#include <Windows.h>
#include "Force.h"

class PhysicsThread :
	public MyThread
{
private:
	ShapeShareObject* _shapeShareObject;

	void CalculateDeltaTime();
	//ms
	float _delta_time;

	LARGE_INTEGER _ticksPerSecond, _consumedCount, _currentCount, _lastCount;
	DWORD procMask, sysMask;

	HANDLE thread;

	//Force
	Force _springforce;

public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };
	static float Dis(const Point& p1, const Point& p2){
		return sqrt((p1.x - p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	};
	int run();
};


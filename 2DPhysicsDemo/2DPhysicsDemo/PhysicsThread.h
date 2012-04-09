#pragma once
#include "mythread.h"
#include <iostream>
#include <math.h>
#include "ShapeShareObject.h"
using namespace std;
#include <Windows.h>

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

public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };

	int run();
};


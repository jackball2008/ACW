#pragma once
#include "mythread.h"
#include <iostream>
#include <math.h>
#include "ShapeShareObject.h"
using namespace std;


class PhysicsThread :
	public MyThread
{
private:
	ShapeShareObject* _shapeShareObject;

	void TraceMouseMove();

public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };

	int run();
};


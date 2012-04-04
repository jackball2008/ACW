#pragma once
#include "mythread.h"
#include <math.h>
#include <iostream>
using namespace std;
#include "MouseShareObject.h"
#include "ShapeShareObject.h"


class ControllerThread :
	public MyThread
{
private:
	MouseShareObject* _mouseShareObject;
	ShapeShareObject* _shapeShareObject;

	float _x,_y;
	bool _down;

public:
	ControllerThread(void);
	~ControllerThread(void);
	int run();
	void SetMouseShareObject(MouseShareObject* p){ _mouseShareObject = p; };
	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };

	static float Area(const Point& p1, const Point& p2, const Point& p3){
		return fabs((p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y));
	};
	static float Mul(const Point& p1, const Point& p2, const Point& p0){
		return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)); 
	};

	static float Dis(const Point& p, const float& x, const float& y){
		return sqrt((p.x - x)*(p.x-1)+(p.y-y)*(p.y-y));
	};
	


	void CheckMouseInShape();

	
};


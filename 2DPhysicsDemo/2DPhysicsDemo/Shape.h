#pragma once
#include "Point.h"
#include <vector>
using namespace std;
class Shape
{

	

public:
	vector<Point>points;

	float velocity;
	float velocity_x;
	float velocity_y;
	float old_velocity_x;
	float old_velocity_y;

	Point direction;

	Point middlepoint;

	
	//force
	float force;
	float force_x;
	float force_y;

	//acceleration
	float acceleration;
	float acceleration_x;
	float acceleration_y;
	//mass
	float mass;
	float point_mass;
	//color
	float r,g,b;
	//mark
	int type;

	bool isvisiable;

	bool becontrolled;

public:
	Shape(void);
	~Shape(void);
	/************************************************************************/
	/* notice this must be thread safe                                       */
	/************************************************************************/
	//square
	virtual void SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4)=0;
	//triangle
	virtual void SetData(const Point& p1,const Point& p2,const Point& p3)=0;
	//line
	virtual void SetData(const Point& p1,const Point& p2)=0;
	/************************************************************************/
	/* read value, maybe do not need thread safe                             */
	/************************************************************************/
// 	virtual vector<Point>* GetData1(){
// 		return &points;
// 	};

	/*const int& GetType(){ return type;};*/


};


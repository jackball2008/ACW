#pragma once
#include "Point.h"
#include <vector>
using namespace std;
class Shape
{

	

public:
	vector<YPoint>points;

	float velocity_x;
	float velocity_y;
	float old_velocity_x;
	float old_velocity_y;
	
	float acceleration_x;
	float acceleration_y;

	float work_force_x;
	float work_force_y;
	float receive_force_x;
	float receive_force_y;


	bool canmove_x;
	bool canmove_y;

	bool isfixed;


	float velocity;
	

	YPoint direction;

	YPoint middlepoint;

	
	//force
	float force;
	

	//acceleration
	float acceleration;
	
	//mass
	float mass;
	float point_mass;
	//color
	float r,g,b;
	//mark
	int type;

	bool isvisiable;

	bool becontrolled;

	int id;

public:
	Shape(void);
	~Shape(void);
	/************************************************************************/
	/* notice this must be thread safe                                       */
	/************************************************************************/
	//square
	virtual void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3,const YPoint& p4)=0;
	//triangle
	virtual void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3)=0;
	//line
	virtual void SetData(const YPoint& p1,const YPoint& p2)=0;
	/************************************************************************/
	/* read value, maybe do not need thread safe                             */
	/************************************************************************/
// 	virtual vector<Point>* GetData1(){
// 		return &points;
// 	};

	/*const int& GetType(){ return type;};*/


};


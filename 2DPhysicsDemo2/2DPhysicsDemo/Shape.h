#pragma once
#include "Point.h"
#include <vector>

using namespace std;
class Shape
{

public:
	//color
	float r,g,b;
	int type;
	bool isvisiable;
	int id;

	//////////////////////////////////////////////////////////////////////////
	//width for x ,y; direction vector for 
	//float xw,yw,dx,dy;==> store to axis
	//float px,py;
	YPoint old_movement;
	YPoint movement;
	
	
	YPoint penmove;
	YPoint pos;//position
	YPoint springforce;
	YPoint acceleration;
	
	YPoint old_force;
	YPoint force;// x y

	YPoint old_velocity;
	YPoint velocity;
	//store points
	vector<YPoint>points;
	int sizeofpoints;//points num
	//dx dy len=z
	vector<YPoint>project_axis;
	//vector<float>project_axis_penAx;
	
	
	float mass;
	

public:
	Shape(void);
	~Shape(void);
	/************************************************************************/
	/* notice this must be thread safe                                       */
	/************************************************************************/
	void Move(const YPoint&dis);
	
};


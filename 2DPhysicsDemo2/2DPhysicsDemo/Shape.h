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

	YPoint penmove;
	YPoint pos;//position
	YPoint springforce;
	YPoint acceleration;
	YPoint force;// x y
	YPoint velocity;
	//store points
	vector<YPoint>points;
	//dx dy len=z
	vector<YPoint>project_axis;
	
	float mass;
	int sizeofpoints;

public:
	Shape(void);
	~Shape(void);
	/************************************************************************/
	/* notice this must be thread safe                                       */
	/************************************************************************/
	void Move(const YPoint&dis);
	
};


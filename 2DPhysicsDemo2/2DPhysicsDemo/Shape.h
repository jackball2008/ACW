#pragma once
#include "Point.h"
#include <vector>

using namespace std;
class Shape
{

public:
	//spring lock
	bool springlocked;
	float lockspringep_dx,lockspringep_dy;

	//color
	float r,g,b;
	int type;
	bool isvisiable;
	int id;

	//////////////////////////////////////////////////////////////////////////

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
	
	float mass;
	
	

public:
	Shape(void);
	~Shape(void);
	/************************************************************************/
	/* notice this must be thread safe                                       */
	/************************************************************************/
	void Move(const YPoint&dis);
	
};


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
	//square
	virtual void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3,const YPoint& p4)=0;
	//triangle
	virtual void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3)=0;
	//line
	virtual void SetData(const YPoint& p1,const YPoint& p2)=0;


	void UpdatePosition()
	{
		/**
		float mix = 0;
		float miy = 0;
		for(int i = 0; i<sizeofpoints;i++)
		{
			points.at(i).x = points.at(i).x+ movement.x;
			mix = mix + points.at(i).x;
			points.at(i).y = points.at(i).y+ movement.y;
			miy = miy + points.at(i).y;
		}
		movement.x = 0;
		movement.y = 0;
		middlepoint.x = mix / sizeofpoints;
		middlepoint.y = miy / sizeofpoints;
		*/

	}


};


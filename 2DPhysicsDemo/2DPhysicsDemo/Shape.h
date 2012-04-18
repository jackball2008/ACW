#pragma once
#include "Point.h"
#include <vector>
/*#include "Mmath.h"*/
#include "mxyMath.h"


using namespace std;

using namespace mxy;

class Shape
{

public:
	//store points
	vector<YPoint>points;
	vec2f middlepoint;
	vec2f force;
	vec2f springforce;
	vec2f acceleration;
	//velocity
	vec2f velocity;
	vec2f old_velocity;
	vec2f movement;
	int sizeofpoints;
	//==================================
	//used in checkCollision
	vec2f pos;
	//==================================
	//mass
	float mass;


	float mgh_power;
	float erfenzhiyimvfang_x;
	float erfenzhiyimvfang_y;
	float mv_x;
	float mv_y;
	//mark hit something
	bool hitsometing;
	bool hitground;

	int type;
	
	float point_mass;
	//color
	float r,g,b;
	bool isvisiable;
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


	void UpdatePosition()
	{
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

	}


};


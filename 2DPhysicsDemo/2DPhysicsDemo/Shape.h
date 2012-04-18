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
<<<<<<< HEAD
	vec2f middlepoint;
	vec2f force;
	vec2f springforce;
	vec2f acceleration;
	//velocity
	vec2f velocity;
	vec2f old_velocity;
	vec2f movement;
	int sizeofpoints;
=======
	YPoint middlepoint;
	//velocity
	YPoint velocity;
>>>>>>> parent of 3a394fe... [modified]还是有问题，碰撞之后的速度不起作用
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



};


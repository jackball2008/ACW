#pragma once
/*#include "Point.h"*/
#include <vector>
/*#include "Mmath.h"*/
#include "mxyMath.h"


using namespace std;

using namespace mxy;

class Shape
{

public:
	//store points
	vector<vec2f>points;
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
// 	bool cantransferpower_y;
// 	bool cantransferpower_x;
/*	bool cantransferpower;*/

	//power
// 	float force_all_x;
// 	float force_all_y;
	//work and receive force on X
// 	float force_out_x;
// 	float force_in_x;
// 	int force_out_dir_x;
// 	int force_in_dir_x;
// 	float velocity_x;
// 	float old_velocity_x;
// 	float acceleration_x;

	//work and receive force on Y
// 	float force_out_y;
// 	float force_in_y;
// 	int force_out_dir_y;
// 	int force_in_dir_y;
// 	float velocity_y;
// 	float old_velocity_y;
// 	float acceleration_y;
// 	
	//shape own properties
	int type;
	bool isrigibody;
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
	virtual void SetData(const vec2f& p1,const vec2f& p2,const vec2f& p3,const vec2f& p4)=0;
	//triangle
	virtual void SetData(const vec2f& p1,const vec2f& p2,const vec2f& p3)=0;
	//line
	virtual void SetData(const vec2f& p1,const vec2f& p2)=0;
	/************************************************************************/
	/* read value, maybe do not need thread safe                             */
	/************************************************************************/
// 	virtual vector<Point>* GetData1(){
// 		return &points;
// 	};

	/*const int& GetType(){ return type;};*/

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


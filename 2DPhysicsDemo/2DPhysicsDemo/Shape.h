#pragma once
#include "Point.h"
#include <vector>
#include "Mmath.h"
using namespace std;
class Shape
{

public:
	//store points
	vector<YPoint>points;
	YPoint middlepoint;
	//velocity
	YPoint velocity;
	//==================================
	//used in checkCollision
	YPoint pos;
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
	bool cantransferpower;

	//power
	float force_all_x;
	float force_all_y;
	//work and receive force on X
	float force_out_x;
	float force_in_x;
	int force_out_dir_x;
	int force_in_dir_x;
	float velocity_x;
	float old_velocity_x;
	float acceleration_x;

	//work and receive force on Y
	float force_out_y;
	float force_in_y;
	int force_out_dir_y;
	int force_in_dir_y;
	float velocity_y;
	float old_velocity_y;
	float acceleration_y;
	
	//shape own properties
	int type;

	bool isrigibody;
// 	bool isground;
// 	bool iscommonshape;
// 	bool isspring;
	

	

	
	
	
	
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
	/************************************************************************/
	/* read value, maybe do not need thread safe                             */
	/************************************************************************/
// 	virtual vector<Point>* GetData1(){
// 		return &points;
// 	};

	/*const int& GetType(){ return type;};*/


};


#pragma once
#include "Point.h"
#include <vector>
using namespace std;
class Shape
{

public:
	//store points
	vector<YPoint>points;

	float mgh_power;
	float erfenzhiyimvfang_x;
	float erfenzhiyimvfang_y;
	float 

	//power
	//work and receive force on X
	float work_force_x;
	float receive_force_x;
	int work_force_dir_x;
	int receive_force_dir_x;
	float velocity_x;
	float old_velocity_x;
	float acceleration_x;

	//work and receive force on Y
	float work_force_y;
	float receive_force_y;
	int work_force_dir_y;
	int receive_force_dir_y;
	float velocity_y;
	float old_velocity_y;
	float acceleration_y;
	
	//shape own properties
	bool isrigibody;
	bool isground;
	bool iscommonshape;
	bool isspring;
	

	YPoint middlepoint;

	
	
	
	//mass
	float mass;
	float point_mass;
	//color
	float r,g,b;
	//mark
	int type;

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


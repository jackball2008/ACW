#pragma once
#include "Point.h"
#include <vector>
using namespace std;
class Shape
{
protected:
	vector<Point>points;

public:
	Shape(void);
	~Shape(void);
	/************************************************************************/
	/* notice this must be thread safe                                       */
	/************************************************************************/
	virtual void SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4,const Point& mid)=0;
	/************************************************************************/
	/* read value, maybe do not need thread safe                             */
	/************************************************************************/
	virtual vector<Point>* GetData(){
		return &points;
	};


};


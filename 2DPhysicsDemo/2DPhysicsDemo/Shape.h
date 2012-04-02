#pragma once
#include "Point.h"
#include <vector>
using namespace std;
class Shape
{
private:
	

protected:
	vector<Point>_points;

	float _speed;

	Point _direction;

	//color
	float _r,_g,_b;
	//mark
	int _type;

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
		return &_points;
	};

	const int& GetType(){ return _type;};


};


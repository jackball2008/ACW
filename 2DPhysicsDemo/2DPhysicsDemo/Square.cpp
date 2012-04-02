#include "Square.h"


Square::Square(void)
{
	//initialize
	
	for(int i=0;i<5;i++)
	{
		Point p;
		_points.push_back(p);
	}
	_type = 3;
}


Square::~Square(void)
{
}

//thread safe, need to be update later
void Square::SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4,const Point& mid){
	//////////////////////////////////////////////////////////////////////////
	_points[0] = p1;
	_points[1] = p2;
	_points[2] = p3;
	_points[3] = p4;
	_points[4] = mid;
	//////////////////////////////////////////////////////////////////////////
}
#include "Triangle.h"


Triangle::Triangle(void)
{
	//initialize
	
	for(int i=0;i<5;i++)
	{
		Point p;
		_points.push_back(p);
		
	}
	_type = 2;
}


Triangle::~Triangle(void)
{
}

//thread safe, need to be update later
void Triangle::SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4,const Point& mid){
	//////////////////////////////////////////////////////////////////////////
	_points[0] = p1;
	_points[1] = p2;
	_points[2] = p3;
	_points[3] = p4;
	_points[4] = mid;
	
	//////////////////////////////////////////////////////////////////////////
}
// vector<Point>* Triangle::GetData(){
// 	return &points;
// }

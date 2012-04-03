#include "Triangle.h"


Triangle::Triangle(void)
{
	//initialize
	
	for(int i=0;i<5;i++)
	{
		Point p;
		points.push_back(p);
		
	}
	type = 2;
}


Triangle::~Triangle(void)
{
}

//thread safe, need to be update later
void Triangle::SetData(const Point& p1,const Point& p2,const Point& p3,const Point& mid){
	//////////////////////////////////////////////////////////////////////////
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	/*points[3] = p4;*/
	points[4] = mid;
	
	//////////////////////////////////////////////////////////////////////////
}
// vector<Point>* Triangle::GetData(){
// 	return &points;
// }

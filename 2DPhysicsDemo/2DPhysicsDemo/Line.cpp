#include "Line.h"


Line::Line(void)
{

	//initialize

	for(int i=0;i<2;i++)
	{
		vec2f p;
		points.push_back(p);
	}
	type = 1;
	
	mass = 0.0f;
	point_mass = 0.0f;

}


Line::~Line(void)
{
}

//thread safe, need to be update later
// void Line::SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4,const Point& mid){
// 	
// 	points[0] = p1;
// 	points[1] = p2;
// 	points[2] = p3;
// 	points[3] = p4;
// 	points[4] = mid;
// 	
// }

void Line::SetData(const vec2f& p1,const vec2f& p2){
	points[0] = p1;
	points[1] = p2;
}

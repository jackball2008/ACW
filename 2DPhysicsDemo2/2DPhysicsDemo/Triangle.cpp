#include "Triangle.h"


Triangle::Triangle(void)
{
	//initialize
	
// 	for(int i=0;i<3;i++)
// 	{
// 		YPoint p;
// 		points.push_back(p);
// 		
// 	}
	type = 2;
	mass = 3.0f;
	sizeofpoints = 3;
}


Triangle::~Triangle(void)
{
}

//thread safe, need to be update later
// void Triangle::SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3){
// 	
// 	points[0] = p1;
// 	points[1] = p2;
// 	points[2] = p3;
// 	
// 	
// 	
// }


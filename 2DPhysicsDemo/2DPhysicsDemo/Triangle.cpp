#include "Triangle.h"


Triangle::Triangle(void)
{
	//initialize
	
	for(int i=0;i<3;i++)
	{
		vec2f p;
		points.push_back(p);
	}
	type = 2;

	mass = 0.4330127019f;
	point_mass = mass/3;
	sizeofpoints = 3;
}


Triangle::~Triangle(void)
{
}

//thread safe, need to be update later
void Triangle::SetData(const vec2f& p1,const vec2f& p2,const vec2f& p3){
	//////////////////////////////////////////////////////////////////////////
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	/*points[3] = p4;*/
	/*points[4] = mid;*/
	
	//////////////////////////////////////////////////////////////////////////
}
// vector<Point>* Triangle::GetData(){
// 	return &points;
// }

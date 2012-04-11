#include "Square.h"


Square::Square(void)
{
	//initialize
	
	for(int i=0;i<4;i++)
	{
		Point p;
		points.push_back(p);
	}
	type = 3;

	mass = 1.0f;
	point_mass = mass/4;
}


Square::~Square(void)
{
}

//thread safe, need to be update later
void Square::SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4){
	//////////////////////////////////////////////////////////////////////////
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	/*points[4] = mid;*/
	//////////////////////////////////////////////////////////////////////////
}
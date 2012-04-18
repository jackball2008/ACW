#include "Line.h"


Line::Line(void)
{

	//initialize

	for(int i=0;i<2;i++)
	{
		YPoint p;
		points.push_back(p);
	}
	type = 1;
	
	mass = 0.0f;
	point_mass = 0.0f;

}


Line::~Line(void)
{
}



void Line::SetData(const YPoint& p1,const YPoint& p2){
	points[0] = p1;
	points[1] = p2;
}

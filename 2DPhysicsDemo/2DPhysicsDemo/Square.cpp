#include "Square.h"


Square::Square(void)
{
	//initialize
	
	for(int i=0;i<4;i++)
	{
		vec2f p;
		points.push_back(p);
	}
	type = 3;

	mass = 1.0f;
	point_mass = mass/4;

	sizeofpoints = 4;

}


Square::~Square(void)
{
}

//thread safe, need to be update later
void Square::SetData(const vec2f& p1,const vec2f& p2,const vec2f& p3,const vec2f& p4){
	//////////////////////////////////////////////////////////////////////////
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	/*points[4] = mid;*/
	//////////////////////////////////////////////////////////////////////////
}
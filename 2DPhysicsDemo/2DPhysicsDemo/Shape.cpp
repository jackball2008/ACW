#include "Shape.h"


Shape::Shape(void)
{
	sizeofpoints = 0;
	mgh_power = 0;
	erfenzhiyimvfang_x = 0;
	erfenzhiyimvfang_y = 0;
	mv_x = 0;
	mv_y = 0;

	hitsometing = false;
	hitground = false;

	


	r=1.0f;
	g=1.0f;
	b=0.0f;

	isvisiable = true;
	
	
	id = 0;

	
}


Shape::~Shape(void)
{
}

#include "Shape.h"


Shape::Shape(void)
{

	r=1.0f;
	g=1.0f;
	b=0.0f;

	isvisiable = true;
	becontrolled = false;
	acceleration = 0.0f;
	velocity = 0.0f;
}


Shape::~Shape(void)
{
}

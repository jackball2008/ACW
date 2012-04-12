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
	acceleration_x = 0.0f;
	acceleration_y = 0.0f;
	velocity_x = 0.0f;
	velocity_y = 0.0f;
}


Shape::~Shape(void)
{
}

#include "Shape.h"


Shape::Shape(void)
{
// 	for(int i=0;i<5;i++)
// 	{
// 		Point p;
// 		points.push_back(p);
// 	}
	r=1.0f;
	g=1.0f;
	b=0.0f;

	visiable = true;
	becontrolled = false;
}


Shape::~Shape(void)
{
}

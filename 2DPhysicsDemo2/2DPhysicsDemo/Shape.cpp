#include "Shape.h"


Shape::Shape(void)
{
	r=1.0f;
	g=1.0f;
	b=0.0f;
	isvisiable = true;
	id = 0;
	sizeofpoints = 0;

	springlocked = false;
	lockspringep_dx = lockspringep_dy = 0;
	
}


Shape::~Shape(void)
{
}


void Shape::Move(const YPoint&dis)
{
	
	pos.Clear();
	for(int i = 0; i< sizeofpoints;i++)
	{
		points.at(i) += dis;
		pos += points.at(i);
	}

	pos /= 4;

}

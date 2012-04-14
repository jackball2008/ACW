#include "SpringLine.h"


SpringLine::SpringLine(void)
{
	type = 0;
	isvisiable = false;
	
	//add two empty points
	
	r = 0.0f;
	g = 1.0f;
	b = 0.0f;

	mass = 0.0f;
	point_mass = 0.0f;
}


SpringLine::~SpringLine(void)
{
}


void SpringLine::Reset(){
	isvisiable = false;
	
}
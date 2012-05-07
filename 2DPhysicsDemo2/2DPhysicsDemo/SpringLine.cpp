#include "SpringLine.h"
#include <math.h>

SpringLine::SpringLine(void)
{
	type = 0;
	isvisiable = false;
	
	//add two empty points
	
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;

	mass = 0.0f;


	/************************************************************************/
	/* set spring line initialize position                                                                     */
	/************************************************************************/
	sp.x = 2.0f;
	sp.y = 2.0f;	
	ep.x = 2.0f;
	ep.y = 2.0f;

	
}


SpringLine::~SpringLine(void)
{
}

// float SpringLine::Length()
// {
// 	return sqrt((sp.x - ep.x)*(sp.x - ep.x)+(sp.y - ep.y)*(sp.y - ep.y));
// }



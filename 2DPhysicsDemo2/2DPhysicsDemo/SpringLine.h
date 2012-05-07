#pragma once
#include "Line.h"

const float ORIGIN_SPRING_X = 2.0f;
const float ORIGIN_SPRING_Y = 2.0f;

class SpringLine :
	public Line
{
public:
	SpringLine(void);
	~SpringLine(void);



	YPoint sp;
	YPoint ep;

	inline float Length()
	{
		return sqrt((sp.x - ep.x)*(sp.x - ep.x)+(sp.y - ep.y)*(sp.y - ep.y));
	}
	
};


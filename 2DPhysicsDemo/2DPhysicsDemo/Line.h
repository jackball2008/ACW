#pragma once
#include "shape.h"
class Line :
	public Shape
{
public:
	Line(void);
	~Line(void);

	void SetData(const vec2f& p1,const vec2f& p2,const vec2f& p3,const vec2f& p4){};
	//triangle
	void SetData(const vec2f& p1,const vec2f& p2,const vec2f& p3){};
	//line
	void SetData(const vec2f& p1,const vec2f& p2);
};


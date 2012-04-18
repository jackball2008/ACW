#pragma once
#include "shape.h"
class Square :
	public Shape
{
public:
	Square(void);
	~Square(void);

	void SetData(const vec2f& p1,const vec2f& p2,const vec2f& p3,const vec2f& p4);

	void SetData(const vec2f& p1,const vec2f& p2,const vec2f& p3){};
	//line
	void SetData(const vec2f& p1,const vec2f& p2){};
};


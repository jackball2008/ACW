#pragma once
#include "shape.h"
class Line :
	public Shape
{
public:
	Line(void);
	~Line(void);

	void SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4,const Point& mid){};

	
	//triangle
	void SetData(const Point& p1,const Point& p2,const Point& p3,const Point& mid){};
	//line
	void SetData(const Point& p1,const Point& p2,const Point& mid);
};


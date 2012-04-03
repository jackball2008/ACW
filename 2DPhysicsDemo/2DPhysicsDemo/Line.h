#pragma once
#include "shape.h"
class Line :
	public Shape
{
public:
	Line(void);
	~Line(void);

	void SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4){};

	
	//triangle
	void SetData(const Point& p1,const Point& p2,const Point& p3){};
	//line
	void SetData(const Point& p1,const Point& p2);
};


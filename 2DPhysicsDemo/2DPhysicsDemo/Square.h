#pragma once
#include "shape.h"
class Square :
	public Shape
{
public:
	Square(void);
	~Square(void);

	void SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4);

	void SetData(const Point& p1,const Point& p2,const Point& p3){};
	//line
	void SetData(const Point& p1,const Point& p2){};
};


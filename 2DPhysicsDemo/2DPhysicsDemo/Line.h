#pragma once
#include "shape.h"
class Line :
	public Shape
{
public:
	Line(void);
	~Line(void);

	void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3,const YPoint& p4){};
	//triangle
	void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3){};
	//line
	void SetData(const YPoint& p1,const YPoint& p2);
};


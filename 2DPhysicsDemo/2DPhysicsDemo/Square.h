#pragma once
#include "shape.h"
class Square :
	public Shape
{
public:
	Square(void);
	~Square(void);

	void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3,const YPoint& p4);

	void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3){};
	//line
	void SetData(const YPoint& p1,const YPoint& p2){};
};


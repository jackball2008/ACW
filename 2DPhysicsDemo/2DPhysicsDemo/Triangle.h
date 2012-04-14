#pragma once
#include "shape.h"
class Triangle :
	public Shape
{



public:
	Triangle(void);
	~Triangle(void);

	void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3,const YPoint& p4){};

	void SetData(const YPoint& p1,const YPoint& p2,const YPoint& p3);
	//line
	void SetData(const YPoint& p1,const YPoint& p2){};
	/*vector<Point>* GetData();*/
};


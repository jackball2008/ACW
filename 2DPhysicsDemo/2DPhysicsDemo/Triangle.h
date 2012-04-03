#pragma once
#include "shape.h"
class Triangle :
	public Shape
{
private:
// 	Point _p1;
// 	Point _p2;
// 	Point _p3;
// 	Point _mid;
// 	


public:
	Triangle(void);
	~Triangle(void);

	void SetData(const Point& p1,const Point& p2,const Point& p3,const Point& p4,const Point& mid){};

	void SetData(const Point& p1,const Point& p2,const Point& p3,const Point& mid);
	//line
	void SetData(const Point& p1,const Point& p2,const Point& mid){};
	/*vector<Point>* GetData();*/
};


#pragma once
#include "mythread.h"
#include <math.h>
#include <iostream>
using namespace std;
#include "MouseShareObject.h"
#include "ShapeShareObject.h"


class ControllerThread :
	public MyThread
{
private:
	MouseShareObject* _mouseShareObject;
	ShapeShareObject* _shapeShareObject;

// 	float _x,_y;
// 	bool _down;

public:
	ControllerThread(void);
	~ControllerThread(void);
	int run();
	void SetMouseShareObject(MouseShareObject* p){ _mouseShareObject = p; };
	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };

	//////////////////////////////////////////////////////////////////////////
	static float Area(const Point& p1, const Point& p2, const Point& p3){
		return fabs((p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y));
	};
	
	static float Mul(const Point& p1, const Point& p2, const Point& p0){
		return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)); 
	};

	static float Dis(const Point& p, const float& x, const float& y){
		return sqrt((p.x - x)*(p.x-1)+(p.y-y)*(p.y-y));
	};

	static int   InsideTriangle(const vector<Point>& pa,const Point& mp){ 
		/*int   i;*/ 
		for   (int i=0;i <3;i++) 
			if   (Mul(mp,pa[i],pa[(i+1)%3])*Mul(mp,pa[(i+2)%3],pa[(i+1)%3])> 0) 
				return   0; 
		return   1; 
	}

	//////////////////////////////////////////////////////////////////////////
	static float GetK(const Point&p1, const Point&p2){
		return (p1.y - p2.y)/(p1.x - p2.x);
	}
	static float GetB(const Point&p1, const Point&p2){
		return (p1.x * p2.y - p2.x*p1.y)/(p1.x-p2.x);
	}

	static bool JudgeTwoLineAcroess(const Point&L1p1, const Point&L1p2,const Point&L2p1, const Point&L2p2){
		float k1 = GetK(L1p1,L1p2);
		float b1 = GetB(L1p1,L1p2);
		float k2 = GetK(L2p1,L2p2);
		float b2 = GetB(L2p1,L2p2);

		if(k1 == k2)
			return false;
		else{
			float x = (b2 - b1)/(k1 - k2);//???

			if( 
				(  x > (L1p1.x>L1p2.x?L1p2.x:L1p1.x) && x < (L1p1.x>L1p2.x?L1p1.x:L1p2.x)  )
				&&
				(  x > (L2p1.x>L2p2.x?L2p2.x:L2p1.x) && x < (L2p1.x>L2p2.x?L2p1.x:L2p2.x)  )

			)

				return true;

			else

				return false;

		}

	}




	//////////////////////////////////////////////////////////////////////////
	


	void CheckMouseInShape();

	
};


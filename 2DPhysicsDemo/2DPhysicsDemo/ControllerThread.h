#pragma once
#include "mythread.h"
#include <math.h>
#include <iostream>
/*#include "Utiles.h"*/
using namespace std;

/*#include "MouseShareObject.h"*/
#include "ShapeShareObject.h"

const Point ORIGIN_P;

class ControllerThread :
	public MyThread
{
private:
	/*MouseShareObject* _mouseShareObject;*/
	ShapeShareObject* _shapeShareObject;

// 	float _x,_y;
// 	bool _down;
	/*int _springcount;*/

public:
	ControllerThread(void);
	~ControllerThread(void);
	int run();
	/*void SetMouseShareObject(MouseShareObject* p){ _mouseShareObject = p; };*/
	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };



	static float Dis(const Point& p, const float& x, const float& y){
		return sqrt((p.x - x)*(p.x-1)+(p.y-y)*(p.y-y));
	};

// 	static int   InsideTriangle(const vector<Point>& pa,const Point& mp){ 
// 		/*int   i;*/ 
// 		for   (int i=0;i <3;i++) 
// 			if   (Mul(mp,pa[i],pa[(i+1)%3])*Mul(mp,pa[(i+2)%3],pa[(i+1)%3])> 0) 
// 				return   0; 
// 		return   1; 
// 	}

	static bool JudgePointInTriangle(const vector<Point>& pa,const Point& mp,const Point& ori){
		/**
		bool result;
		for(int i= 0;i < 3; i++){

			if(InsideTriangle(pa,mp) == 0)
				result = false;
			else
				result = true;

		}
		return result;
		*/
		//////////////////////////////////////////////////////////////////////////
		int numofacroess = 0;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(0),pa.at(1)))
			numofacroess++;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(1),pa.at(2)))
			numofacroess++;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(2),pa.at(0)))
			numofacroess++;
		if(/*numofacroess==1*/!(numofacroess%2==0))
			return true;
		else
			return false;
	}

	static bool JudgePointInPologon(const vector<Point>& pa,const Point& mp,const Point& ori){
		int numofacroess = 0;
		int nsize = pa.size();
		for(int i=0; i<nsize;i++){
			if((i+1)<nsize){
				if(JudgeTwoLineAcroess(ori,mp,pa.at(i),pa.at(i+1)))
					numofacroess++;
			}else{
				if(JudgeTwoLineAcroess(ori,mp,pa.at(i),pa.at(0)))
					numofacroess++;
			}
		}
		if(!(numofacroess%2==0))
			return true;
		else
			return false;
	}

	//////////////////////////////////////////////////////////////////////////
	/** wrong function
	static float GetK(const Point&p1, const Point&p2){
		return (p1.y - p2.y)/(p1.x - p2.x);
	}
	static float GetB(const Point&p1, const Point&p2){
		return (p1.x * p2.y - p2.x*p1.y)/(p1.x-p2.x);
	}

	
	static bool JudgeTwoLineAcroess2(const Point&L1p1, const Point&L1p2,const Point&L2p1, const Point&L2p2){
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
	*/
	/************************************************************************/
	/*
	Public Boolean isIntersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) { 

	double v1=(x2-x1)*(y4-y1) - (y2-y1)*(x4-x1); 
	double v2=(x2-x1)*(y3-y1) - (y2-y1)*(x3-x1); 
	if(v1*v2 >= 0) { 
	return false; 
	} 
	double v3=(x4-x3)*(y2-y3) - (y4-y3)*(x2-x3); 
	double v4=(x4-x3)*(y1-y3) - (y4-y3)*(x1-x3); 
	if(v3*v4 >= 0) { 
	return false; 
	} 
	return true; 
	}                                                                     */
	/************************************************************************/
	static bool JudgeTwoLineAcroess(const Point&L1p1, const Point&L1p2,const Point&L2p1, const Point&L2p2){
		float v1 = (L1p2.x - L1p1.x)*(L2p2.y-L1p1.y) - (L1p2.y-L1p1.y)*(L2p2.x-L1p1.x);
		float v2 = (L1p2.x-L1p1.x)*(L2p1.y-L1p1.y)-(L1p2.y-L1p1.y)*(L2p1.x-L1p1.x);
		if(v1*v2 >= 0) { 
			return false; 
		}
		float v3 = (L2p2.x-L2p1.x)*(L1p2.y-L2p1.y)-(L2p2.y-L2p1.y)*(L1p2.x-L2p1.x);
		float v4 = (L2p2.x-L2p1.x)*(L1p1.y-L2p1.y)-(L2p2.y-L2p1.y)*(L1p1.x-L2p1.x);
		if(v3*v4 >= 0) { 
			return false; 
		} 
		return true; 
	}
	static bool JudgePointInSquare(const vector<Point>& pa,const Point& mp,const Point& ori){
		int numofacroess = 0;
		
		if( 
			JudgeTwoLineAcroess(ori,mp,pa.at(0),pa.at(1))
			)
			numofacroess++;
		if( 
			JudgeTwoLineAcroess(ori,mp,pa.at(1),pa.at(2))
			)
			numofacroess++;
		if( 
			JudgeTwoLineAcroess(ori,mp,pa.at(2),pa.at(3))
			)
			numofacroess++;
		if( 
			JudgeTwoLineAcroess(ori,mp,pa.at(3),pa.at(0))
			)
			numofacroess++;

// 		int temp = 0;
// 
// 		if(numofacroess == 2)
// 			temp = 1;
// 		if(numofacroess == 3)
// 			temp = 2;
// 		if(numofacroess == 4)
// 			temp = 3;

		if(/*numofacroess==1*/!(numofacroess%2==0))
			return true;
		else
			return false;

	}




	//////////////////////////////////////////////////////////////////////////
	


	void CheckSpringLineStartPointInShape();

	
};


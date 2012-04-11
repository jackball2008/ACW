#pragma once
#include "mythread.h"
#include <iostream>
#include <math.h>
#include "ShapeShareObject.h"
using namespace std;
#include <Windows.h>
#include "Force.h"

const float SPRING_FACTOR = 2.5f;
const Point ORIGIN_P_PHYSICS;
class PhysicsThread :
	public MyThread
{
private:
	ShapeShareObject* _shapeShareObject;

	
	//ms
	float _delta_time;

	LARGE_INTEGER _ticksPerSecond, _consumedCount, _currentCount, _lastCount;
	DWORD procMask, sysMask;

	HANDLE thread;

	//Force
	Force _springforce;

	//functions
	void CalculateDeltaTime();
	void CalculatePyhsics();
	Point _checkp;

public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };

	static float Dis(const Point& p1, const Point& p2){
		return sqrt((p1.x - p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	};

	static bool JudgePointInTriangle(const vector<Point>& pa,const Point& mp,const Point& ori){
		int numofacroess = 0;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(0),pa.at(1)))
			numofacroess++;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(1),pa.at(2)))
			numofacroess++;
		if(JudgeTwoLineAcroess(ori,mp,pa.at(2),pa.at(0)))
			numofacroess++;
		if(!(numofacroess%2==0))
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


		if(!(numofacroess%2==0))
			return true;
		else
			return false;

	}

	int run();
};


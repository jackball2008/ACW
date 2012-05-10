#pragma once
#include "RigidBody.h"
#include <Windows.h>
//#include "GXBase.h"
//using namespace gxbase;
#include <vector>
using std::vector;

const float ORIGIN_SPRING_X = 2.0f;
const float ORIGIN_SPRING_Y = 2.0f;

class SpringLine:
	public _RigidBody
{
public:
	SpringLine(void);
	~SpringLine(void){};



	Vector sp;
	Vector ep;

	inline float Length()
	{
		return sqrt((sp.x - ep.x)*(sp.x - ep.x)+(sp.y - ep.y)*(sp.y - ep.y));
	}
};



class ShareMem
{
public:
	ShareMem();
	~ShareMem();

	vector <_RigidBody*>renderObjects;
	////////////////////////////
	float mouse_x,mouse_y;
	bool left_hold;
	SpringLine *springLine;
	//////////////////////////////
	bool Acquire(){
		return (WaitForSingleObject(mutex,5000L) == WAIT_OBJECT_0);
	}
	
	void Release(){
		ReleaseMutex(mutex);
	}
private:
	HANDLE mutex;

	
};


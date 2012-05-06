#pragma once
#include "RigidBody.h"
#include <Windows.h>
//#include "GXBase.h"
//using namespace gxbase;
#include <vector>
using std::vector;

class ShareMem
{
public:
	ShareMem();
	~ShareMem();

	vector <_RigidBody*>renderObjects;
	
	bool Acquire(){
		return (WaitForSingleObject(mutex,5000L) == WAIT_OBJECT_0);
	}
	
	void Release(){
		ReleaseMutex(mutex);
	}
private:
	HANDLE mutex;
};


#pragma once
#include <Windows.h>
#include "GXBase.h"
using namespace gxbase;

class ShareMem
{
public:
	ShareMem();
	~ShareMem();

	bool Acquire(){
		return (WaitForSingleObject(mutex,5000L) == WAIT_OBJECT_0);
	}
	
	void Release(){
		ReleaseMutex(mutex);
	}
private:
	HANDLE mutex;
};


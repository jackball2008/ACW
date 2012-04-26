#pragma once
#include "MyThread.h"
#include <iostream>
#include "ShareMem.h"
#include <Windows.h>

using std::iostream;

class PhysicThread :
	MyThread
{
public:
	PhysicThread(void);
	~PhysicThread(void);
private:
	ShareMem *_shareobject;

	HANDLE thread;
};


#pragma once
#include "basethread.h"
class PhysicsThread :
	public BaseThread
{
public:
	PhysicsThread(void);
	~PhysicsThread(void);

	void waitForTermination();
	int run();
};


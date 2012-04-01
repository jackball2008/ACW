#pragma once
#include "basethread.h"
class ControllerThread :
	public BaseThread
{
public:
	ControllerThread(void);
	~ControllerThread(void);

	/*void waitForTermination();*/
	int run();
};


#pragma once
#include "basethread.h"
class RenderThread :
	public BaseThread
{
public:
	RenderThread(void);
	~RenderThread(void);

	void waitForTermination();
	int run();
};


#pragma once
#include "basethread.h"
class NetReceiveThread :
	public BaseThread
{
public:
	NetReceiveThread(void);
	~NetReceiveThread(void);

	void waitForTermination();
	int run();
};


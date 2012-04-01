#pragma once
#include "basethread.h"
class NetSendThread :
	public BaseThread
{
public:
	NetSendThread(void);
	~NetSendThread(void);

	void waitForTermination();
	int run();
};


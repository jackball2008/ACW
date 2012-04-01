#pragma once
#include "basethread.h"

class NetSendThread :
	public BaseThread
{
public:
	NetSendThread(void);
	~NetSendThread(void);

	
	int run();
};


#pragma once
#include "basethread.h"

class NetReceiveThread :
	public BaseThread
{
public:
	NetReceiveThread(void);
	~NetReceiveThread(void);

	
	int run();
};


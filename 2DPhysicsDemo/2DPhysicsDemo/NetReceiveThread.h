#pragma once
#include "mythread.h"
#include <iostream>
using namespace std;

class NetReceiveThread :
	public MyThread
{
public:
	NetReceiveThread(void);
	~NetReceiveThread(void);

	int run();
};


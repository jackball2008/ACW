#pragma once
#include "mythread.h"
#include <iostream>
using namespace std;

class NetSendThread :
	public MyThread
{
public:
	NetSendThread(void);
	~NetSendThread(void);

	int run();
};


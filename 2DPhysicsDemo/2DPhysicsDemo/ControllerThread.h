#pragma once
#include "mythread.h"
#include <iostream>
using namespace std;

class ControllerThread :
	public MyThread
{
public:
	ControllerThread(void);
	~ControllerThread(void);
	int run();
};


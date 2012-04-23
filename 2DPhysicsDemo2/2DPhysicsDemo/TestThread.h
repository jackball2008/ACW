#pragma once
#include "mythread.h"
#include <iostream>

using namespace std;
class TestThread :
	public MyThread
{
public:
	TestThread(void);
	~TestThread(void);

	int run();
};


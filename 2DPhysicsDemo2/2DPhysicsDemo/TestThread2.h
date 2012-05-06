#pragma once
#include "mythread.h"
#include <iostream>

using namespace std;
class TestThread2 :
	public MyThread
{
public:
	TestThread2(void);
	~TestThread2(void);

	int run();
};


#pragma once
#include "mythread.h"
#include <iostream>
using namespace std;


class PhysicsThread :
	public MyThread
{
public:
	PhysicsThread(void);
	~PhysicsThread(void);

	int run();
};


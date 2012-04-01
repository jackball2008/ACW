#pragma once
#include "mythread.h"
#include <iostream>
using namespace std;

class RenderThread :
	public MyThread
{
public:
	RenderThread(void);
	~RenderThread(void);

	int run();
};


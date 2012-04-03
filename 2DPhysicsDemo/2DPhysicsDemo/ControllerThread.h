#pragma once
#include "mythread.h"
#include <iostream>
using namespace std;
#include "MouseShareObject.h"

class ControllerThread :
	public MyThread
{
private:
	MouseShareObject* _mouseShareObject;

public:
	ControllerThread(void);
	~ControllerThread(void);
	int run();
	void SetMouseShareObject(MouseShareObject* p){ _mouseShareObject = p; };
};


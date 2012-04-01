#pragma once
#include <GXBase.h>
#include <iostream>
#include "MyWindow.h"
#include "TestThread.h"
#include "TestThread2.h"

using namespace gxbase;
using namespace std;
class PhysicsApp:
	public App
{
private:
	MyWindow _mywindow;

	TestThread* _testThread;
	TestThread2* _testThread2;
public:
	PhysicsApp(void);
	~PhysicsApp(void);

	void OnCreate();
	void OnDestroy();

};


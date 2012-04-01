#pragma once
#include <GXBase.h>
#include <iostream>
#include "MyWindow.h"
// #include "TestThread.h"
// #include "TestThread2.h"
//////////////////////////////////////////////////////////////////////////
#include "NetReceiveThread.h"
#include "NetSendThread.h"
#include "ControllerThread.h"
#include "PhysicsThread.h"
#include "RenderThread.h"

using namespace gxbase;
using namespace std;
class PhysicsApp:
	public App
{
private:
	MyWindow _mywindow;

// 	TestThread* _testThread;
// 	TestThread2* _testThread2;
	//real work thread
	NetReceiveThread* _netReceiveThread;
	NetSendThread* _netSendThread;
	ControllerThread* _controllerThread;
	PhysicsThread* _physicsThread;
	RenderThread* _renderThread;
public:
	PhysicsApp(void);
	~PhysicsApp(void);

	void OnCreate();
	void OnDestroy();

};


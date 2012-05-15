#pragma once
#include "PhysicThread.h"
#include "MyWindow.h"
#include "ClientThread.h"
#include "ServerThread.h"
class MyApp:public App
{
public:
	MyApp(void);
	~MyApp(void);

	void OnCreate();
	void OnDestroy();

private:
	
	MyWindow _mywindow;

	PhysicThread *_physicsThread;
	ClientThread *_clientThread;
	ServerThread *_serverThread;

	ShareMem _shapeobject;
	void Initializeposition();
};


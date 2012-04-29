#pragma once
#include "PhysicThread.h"
#include "MyWindow.h"

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

	ShareMem _shapeobject;
	void Initializeposition();
};


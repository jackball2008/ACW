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

//////////////////////////////////////////////////////////////////////////
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Line.h"
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* share objects                                                                     */
/************************************************************************/
#include "ShapeShareObject.h"


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

	/************************************************************************/
	/* share object                                                                     */
	/************************************************************************/
	/*vector<Shape*>_renderObjects;*/
	ShapeShareObject _shapeShareObject;

	/************************************************************************/
	/* functions                                                                     */
	/************************************************************************/
	//initialize all shape position, calculate all points' position and store them into _renderObjects
	void InitializeAllShpes();

public:
	PhysicsApp(void);
	~PhysicsApp(void);

	void OnCreate();
	void OnDestroy();

	//static PhysicsApp &Get();

	//vector<Shape*> GetElements() const { return _renderObjects;};

};


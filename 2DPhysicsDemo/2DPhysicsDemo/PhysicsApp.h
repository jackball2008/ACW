#pragma once
#include <GXBase.h>
#include <iostream>
#include "MyWindow.h"

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
#include "MouseShareObject.h"


using namespace gxbase;
using namespace std;
class PhysicsApp:
	public App
{
private:
	MyWindow _mywindow;

	//real work thread
	NetReceiveThread* _netReceiveThread;
	NetSendThread* _netSendThread;
	ControllerThread* _controllerThread;
	PhysicsThread* _physicsThread;
	RenderThread* _renderThread;

	/************************************************************************/
	/* share object                                                                     */
	/************************************************************************/
	ShapeShareObject _shapeShareObject;
	MouseShareObject _mouseShareObject;
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



};


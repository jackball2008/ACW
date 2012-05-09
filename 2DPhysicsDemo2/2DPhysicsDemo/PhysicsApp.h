#pragma once
#include <GXBase.h>
#include <iostream>
#include "MyWindow.h"

//////////////////////////////////////////////////////////////////////////
#include "NetReceiveThread.h"
#include "NetSendThread.h"
#include "ControllerThread.h"
#include "PhysicsThread.h"


//////////////////////////////////////////////////////////////////////////
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Line.h"
#include "SpringLine.h"
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

	//real work thread
	NetReceiveThread* _netReceiveThread;
	NetSendThread* _netSendThread;
	PhysicsThread* _physicsThread;
	

	/************************************************************************/
	/* share object                                                                     */
	/************************************************************************/
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

};


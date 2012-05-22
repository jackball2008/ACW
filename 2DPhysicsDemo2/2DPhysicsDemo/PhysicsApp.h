#pragma once
// put these file first because winsocket2.h must before window.h
//////////////////////////////////////////////////////////////////////////
#include "NetReceiveThread.h"
#include "PhysicsThread.h"
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include <GXBase.h>
#include <iostream>
#include "MyWindow.h"
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
	NetReceiveThread* _netWorkThread;
	//NetSendThread* _netSendThread;
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

	int sid_back;

public:
	PhysicsApp(void);
	~PhysicsApp(void);

	void OnCreate();
	void OnDestroy();

	static PhysicsApp & Get();

	void AddShape();

};


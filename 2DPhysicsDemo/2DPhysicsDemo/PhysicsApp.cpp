#include "PhysicsApp.h"

static PhysicsApp theApp;
PhysicsApp::PhysicsApp(void)
{
// 	_testThread = new TestThread();
// 	_testThread2 = new TestThread2();
	//////////////////////////////////////////////////////////////////////////
	_netReceiveThread = new NetReceiveThread();
	_netSendThread = new NetSendThread();
	_controllerThread = new ControllerThread();
	_physicsThread = new PhysicsThread();
	_renderThread = new RenderThread();
}


PhysicsApp::~PhysicsApp(void)
{
// 	delete _testThread;
// 	delete _testThread2;
	//////////////////////////////////////////////////////////////////////////
	delete _netReceiveThread;
	delete _netSendThread;
	delete _controllerThread;
	delete _physicsThread;
	delete _renderThread;
}

PhysicsApp &PhysicsApp::Get()
{

	return theApp;
}

void PhysicsApp::OnCreate(){
	
	_mywindow.Show();
	_mywindow.SetSize(1024,768);

// 	_testThread->start();
// 	_testThread2->start();

	_netReceiveThread->start();
	_netSendThread->start();
	_controllerThread->start();
	_physicsThread->start();
	_renderThread->start();
}

void PhysicsApp::OnDestroy(){
// 	_testThread->terminate();
// 	_testThread->waitForTermination();

// 	_testThread2->terminate();
// 	_testThread2->waitForTermination();
	//////////////////////////////////////////////////////////////////////////
	_netReceiveThread->terminate();
	_netReceiveThread->waitForTermination();

	_netSendThread->terminate();
	_netSendThread->waitForTermination();

	_controllerThread->terminate();
	_controllerThread->waitForTermination();

	_physicsThread->terminate();
	_physicsThread->waitForTermination();

	_renderThread->terminate();
	_renderThread->waitForTermination();
}

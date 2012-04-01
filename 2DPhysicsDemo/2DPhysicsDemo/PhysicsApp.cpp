#include "PhysicsApp.h"

static PhysicsApp theApp;
PhysicsApp::PhysicsApp(void)
{
	_testThread = new TestThread();
	_testThread2 = new TestThread2();
}


PhysicsApp::~PhysicsApp(void)
{
	delete _testThread;
	delete _testThread2;
}

void PhysicsApp::OnCreate(){
	cout<<"okok"<<endl;
	_mywindow.Show();
	_mywindow.SetSize(640,480);

	_testThread->start();
	_testThread2->start();
}

void PhysicsApp::OnDestroy(){
	_testThread->terminate();
	_testThread->waitForTermination();

	_testThread2->terminate();
	_testThread2->waitForTermination();
}

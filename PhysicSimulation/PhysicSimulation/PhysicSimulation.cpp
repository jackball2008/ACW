#include "PhysicSimulation.h"

static PhysicSimulation theApp;


PhysicSimulation::PhysicSimulation(void)
{
	//initialize all work threads
 	_netReceiveThread = new NetReceiveThread();
// 	_netSendThread = new NetSendThread();
// 	_controllerThread = new ControllerThread();
// 	_renderThread = new RenderThread();
// 	_physicsThread = new PhysicsThread();
}


PhysicSimulation::~PhysicSimulation(void)
{
	//delete all work threads
 	delete _netReceiveThread;
// 	delete _netSendThread;
// 	delete _controllerThread;
// 	delete _renderThread;
// 	delete _physicsThread;
}

PhysicSimulation &PhysicSimulation::Get()
{
	return theApp;
}

void PhysicSimulation::OnCreate()
{
	window.Show();
	window.SetSize(640,480);
	window.SetTitle("2DPhysics Demo");



	
}

void PhysicSimulation::OnDestroy()
{
	_netReceiveThread->terminate();
	_netReceiveThread->waitForTermination();
	
// 	_netSendThread->terminate();
// 	_netSendThread->waitForTermination();

}





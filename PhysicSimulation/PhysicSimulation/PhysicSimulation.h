#pragma once
#include <GXBase.h>
#include "PhysicSimulationWindow.h"
#include "NetReceiveThread.h"
//#include "NetSendThread.h"
// #include "ControllerThread.h"
// #include "RenderThread.h"
// #include "PhysicsThread.h"

using namespace gxbase;
class PhysicSimulation : public App
{
private:
	//main framework thread
	PhysicSimulationWindow window;

	//thread
 	NetReceiveThread *_netReceiveThread;
// 	NetSendThread *_netSendThread;
// 	ControllerThread *_controllerThread;
// 	RenderThread *_renderThread;
// 	PhysicsThread *_physicsThread;


public:
	PhysicSimulation(void);
	~PhysicSimulation(void);

	static PhysicSimulation &Get();

	void OnCreate();
	void OnDestroy();

};


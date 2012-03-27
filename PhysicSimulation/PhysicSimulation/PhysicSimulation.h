#pragma once
#include <GXBase.h>
#include "PhysicSimulationWindow.h"

using namespace gxbase;
class PhysicSimulation : public App
{
public:
	//PhysicSimulation(void);
	//~PhysicSimulation(void);

	PhysicSimulationWindow window;

	void OnCreate();

};


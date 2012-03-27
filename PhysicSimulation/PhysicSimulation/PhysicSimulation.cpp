#include "PhysicSimulation.h"

static PhysicSimulation theApp;

void PhysicSimulation::OnCreate()
{
	window.Show();
	window.SetSize(640,480);
	if(!window.HasExtension("GL_ARB_vertex_buffer_object") )
	{
		MsgPrintf("Vertex buffer object extension not found\n");
	}


}

/**
PhysicSimulation::PhysicSimulation(void)
{
}


PhysicSimulation::~PhysicSimulation(void)
{
}
*/
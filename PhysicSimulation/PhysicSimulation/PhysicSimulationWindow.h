#pragma once
#include <GXBase.h>
/*#include "glwindowex.h"*/
using namespace gxbase;
class PhysicSimulationWindow :
	public GLWindowEx
{
public:
	PhysicSimulationWindow(void);
	//~PhysicSimulationWindow(void);
	/************************************************************************/
	/* main logic                                                                     */
	/************************************************************************/
	void	OnCreate();
	void	OnDisplay();
	void	OnIdle();
	void	OnKeyboard(int key, bool down);
	void	OnMouseMove(int x, int y);
	void	OnMouseButton(MouseButton button, bool down);
	void	OnResize();
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	void	OnUpdate();
	

};


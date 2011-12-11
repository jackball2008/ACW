#pragma once
#include "GXBase.h"
#include <iostream>
#include "SnowWorld.h"

using std::cout;
using std::endl;

using namespace gxbase;


class SnowWorldWindow : public GLWindowEx
{
public:
	SnowWorldWindow(void);
	~SnowWorldWindow(void);

	void OnCreate();
	void OnDisplay();
	void OnIdle();
	void OnKeyboard(int key, bool down);
	void OnMouseMove(int x, int y);
	void OnMouseButton(MouseButton button, bool down);
	void OnUpdate();


	/************************************************************************/
	/* shadow and mutil texture  Flag                                                                   */
	/************************************************************************/
	bool   _bHaveMultitex;	// do we have mulitexture support?
	bool   _bMultitex;		// using multitexturing?
	/************************************************************************/
	/* Simulation data                                               */
	/************************************************************************/
	const float _angleInc;
	float _angle;
	float _cameraAngle, _cameraPositionZ, _cameraRotation,_cameraHerical;
	bool _leftDown, _rightDown;

	//world
	SnowWorld world;

};


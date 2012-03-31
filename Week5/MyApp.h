#pragma once

#include "GXBase.h"
using namespace gxbase;

#include "MyWnd.h"
#include "BallPhysics.h"

//-----------------------------------------------------------------------------

/**
 * Custom application class, derived from GXBase App class
 */
class MyApp :public App {
private:
	MyWnd  _wnd;	

	// Shared object
	BallPhysics *_ballPhys1;
	BallPhysics *_ballPhys2;
public:
	MyApp();
	~MyApp();

	void OnCreate();
	void OnDestroy();

	BallPhysics *getBallPhysics() const { return _ballPhys1; }

	BallPhysics *getBallPhysics2() const { return _ballPhys2; }

	static MyApp &Get();
};

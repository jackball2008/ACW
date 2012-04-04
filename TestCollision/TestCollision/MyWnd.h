#pragma once
#include "GXBase.h"
using namespace gxbase;

//---------------------------------------------------------------//
// custom window class, derived from GXBase GLWindow             //
//---------------------------------------------------------------//

class MyWnd :public GLWindow{
	bool _bToggleDisplay;

public:
	MyWnd(){ _bToggleDisplay =true;}
	void OnDisplay();
	void OnCreate();
	void OnIdle();
	void OnKeyboard(int key, bool down);




};
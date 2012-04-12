#pragma once
#include "MyPhysics.h"
#include <GXBase.h>
using gxbase::GLWindowEx;
using gxbase::App;
#include <vector>
using std::vector;



class MyWindow : 
	public GLWindowEx
{
public:
	MyWindow();
	~MyWindow(void);

	void  OnCreate();
	void  OnDisplay();
	void  OnIdle();
	/*void OnResize(int w, int h);*/
	MyPhysics _myphysics;
	

private:
	float current_time;

};

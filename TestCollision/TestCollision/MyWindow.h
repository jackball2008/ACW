#pragma once
//#include "MyPhysics.h"
#include <GXBase.h>
using namespace gxbase;




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
	/*MyPhysics _myphysics;*/
	void SetShapeObject(ShareMem*);

private:
	float current_time;

	ShareMem*_shapeobject;
};

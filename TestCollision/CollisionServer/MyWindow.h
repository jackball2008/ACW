#pragma once
//#include "MyPhysics.h"
#include <GXBase.h>
using namespace gxbase;
#include "ShareMem.h"



class MyWindow : 
	public GLWindowEx
{
public:
	MyWindow();
	~MyWindow(void);

	void  OnCreate();
	void  OnDisplay();
	void  OnIdle();
	void	OnMouseMove(int x, int y);
	void	OnMouseButton(MouseButton button, bool down);
	/*void OnResize(int w, int h);*/
	/*MyPhysics _myphysics;*/
	void SetShapeObject(ShareMem*);

private:
	float current_time;
	_RigidBody* RID;
	ShareMem*_shapeobject;
	/************************************************************************/
	/* mouse operation valuable                                                                     */
	/************************************************************************/
	bool ishold;
	bool left_down;
	bool last_left_down;

	float mouse_x,mouse_y;
};

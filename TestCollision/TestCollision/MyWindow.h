#pragma once
#include "RigidBody.h"
#include <GXBase.h>
using gxbase::GLWindowEx;
#include <vector>
using std::vector;


class MyWindow : 
	public GLWindowEx
{
public:
	MyWindow(void);
	~MyWindow(void);

	void  OnCreate();
	void  OnDisplay();
	void  OnIdle();
	_RigidBody rigidbody1,rigidbody2;

};

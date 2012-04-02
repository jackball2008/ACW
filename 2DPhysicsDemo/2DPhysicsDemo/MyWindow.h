#pragma once
/*#include "glwindowex.h"*/
#include <GXBase.h>
using namespace gxbase;
#include <vector>
using namespace std;


class MyWindow :
	public GLWindowEx
{
public:
	MyWindow(void);
	~MyWindow(void);

	void	OnCreate();
	void	OnDisplay();
	void	OnIdle();
	void	OnKeyboard(int key, bool down);
	void	OnMouseMove(int x, int y);
	void	OnMouseButton(MouseButton button, bool down);



};


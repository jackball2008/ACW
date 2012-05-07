#pragma once
#include <GXBase.h>
using namespace gxbase;
#include <vector>
using namespace std;

/************************************************************************/
/* share object                                                                     */
/************************************************************************/
#include "ShapeShareObject.h"
#include "MouseShareObject.h"


class MyWindow :
	public GLWindowEx
{
private:
	ShapeShareObject* _shapeShareObject;
	MouseShareObject* _mouseShareObject;

	YPoint _currentmouseposition;

	/************************************************************************/
	/* mouse operation valuable                                                                     */
	/************************************************************************/
	bool ishold;
	bool left_down;
	bool last_left_down;

	float mouse_x,mouse_y;

	
public:
	MyWindow(void);
	~MyWindow(void);

	void	OnCreate();
	void	OnDisplay();
	void	OnIdle();
	void	OnKeyboard(int key, bool down);
	void	OnMouseMove(int x, int y);
	void	OnMouseButton(MouseButton button, bool down);

	void SetShapeShareObject( ShapeShareObject*);
	void SetMouseShareObject(MouseShareObject*);

};


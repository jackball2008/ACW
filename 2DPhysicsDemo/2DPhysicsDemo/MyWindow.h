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


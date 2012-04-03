#pragma once
#include "mythread.h"
#include <iostream>
#include <GXBase.h>

using namespace gxbase;

using namespace std;

#include "ShapeShareObject.h"


class RenderThread :
	public MyThread
{
private:
	ShapeShareObject* _shapeShareObject;

	/*HDC			hDC;*/
public:
	RenderThread(void);
	~RenderThread(void);

	int run();
	void SetShapeShareObject( ShapeShareObject*);

	void Render();
};


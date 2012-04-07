#include "ShapeShareObject.h"


ShapeShareObject::ShapeShareObject(void)
{
	mutex = CreateMutex(NULL, FALSE, "shapeMutes");
	last_left_down = false;
	left_down = false;
	left_hold = false;
}


ShapeShareObject::~ShapeShareObject(void)
{
	CloseHandle(mutex);
}





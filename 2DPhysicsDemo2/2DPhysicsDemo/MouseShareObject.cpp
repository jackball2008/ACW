#include "MouseShareObject.h"


MouseShareObject::MouseShareObject(void):u(0),v(0),old_u(0),old_v(0),left_down(false), right_down(false)
{
	mutex = CreateMutex(NULL, FALSE, "mouseMutes");
}


MouseShareObject::~MouseShareObject(void)
{
	CloseHandle(mutex);
}




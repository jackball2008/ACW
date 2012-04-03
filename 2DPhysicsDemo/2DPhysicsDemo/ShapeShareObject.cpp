#include "ShapeShareObject.h"


ShapeShareObject::ShapeShareObject(void)
{
	mutex = CreateMutex(NULL, FALSE, "shapeMutes");
}


ShapeShareObject::~ShapeShareObject(void)
{
	CloseHandle(mutex);
}

// void ShapeShareObject::SetData(Shape* p){
// 	renderObjects.push_back(p);
// }



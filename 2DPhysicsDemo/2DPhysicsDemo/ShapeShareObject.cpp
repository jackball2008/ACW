#include "ShapeShareObject.h"


ShapeShareObject::ShapeShareObject(void)
{
}


ShapeShareObject::~ShapeShareObject(void)
{
}

void ShapeShareObject::SetData(Shape* p){
	_renderObjects.push_back(p);
}

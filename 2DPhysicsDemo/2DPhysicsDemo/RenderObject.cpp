#include "RenderObject.h"


RenderObject::RenderObject(void)
{
}


RenderObject::~RenderObject(void)
{
}

RenderObject::RenderObject(const int& type){
	if( type == 1 ){
		_shape = new Triangle();
	}
	if(type == 2){
		_shape = new Square();
	}
}

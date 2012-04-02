#pragma once
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"


class RenderObject
{
private:
	Shape* _shape;

	float _speed;

	Point _direction;

public:
	RenderObject(void);
	RenderObject(const int& type);
	~RenderObject(void);
};


#pragma once
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Line.h"

class ShapeShareObject
{
private:
	vector<Shape*>_renderObjects;

public:
	ShapeShareObject(void);
	~ShapeShareObject(void);

	void SetData(Shape*);

	vector<Shape*> GetData() const { return _renderObjects;};

};


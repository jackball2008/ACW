#pragma once

#include <GXBase.h>
#include "Vertex.h"
#include "DisplayObjectModel.h"
using namespace gxbase;

class Terrain:public DisplayObjectModel{

private:
	Image _heightfield;
//	Vertex* _vertexarray;
	float (*_vertexarray)[3];
	float (*_normalarray)[3];
	GLuint *_indexarray;
	float (*_texarray)[2];
	int _width,_height;

public:
	Terrain();
	~Terrain();
	void OnCreate();
	void Draw();
	void normal(bool normon) const;

private:
	void _gen_normals();
	void _normalize();

};
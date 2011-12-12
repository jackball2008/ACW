#pragma once
#include "GXBase.h"

#include "mxyVector.h"
typedef mxy::vec3<float> vec3f;
typedef mxy::vec4<float> vec4f;

using namespace gxbase;

class FlashLighting
{
public:
	FlashLighting(void);
	~FlashLighting(void);


	void Start();
	void Stop();

	void Draw();

	bool work;
	vec3f pos;
	GLfloat p1[3];
	GLfloat p2[3];
};


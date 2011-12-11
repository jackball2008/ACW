#pragma once
#include "ISprite.h"
#include "mxyVector.h"
typedef mxy::vec3<float> vec3f;

class BasicSprite:public ISprite
{
public:
	BasicSprite(void);
	virtual ~BasicSprite(void);

	vec3f positionV;
	vec3f scaleV;
	vec3f rotateV;

};


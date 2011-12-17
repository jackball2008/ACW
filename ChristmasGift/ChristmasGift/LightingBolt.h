#pragma once
#include "displayobjectmodel.h"
#include "mxyVector.h"
typedef mxy::vec3<float> vec3f;

class LightingBolt :
	public DisplayObjectModel
{
public:
	LightingBolt(void);
	~LightingBolt(void);

	void Update(const float& t);
	void Draw();

	bool working;
	void Start();
	void Stop();

	
};


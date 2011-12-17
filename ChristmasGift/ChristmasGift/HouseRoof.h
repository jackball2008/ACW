#pragma once
#include "displayobjectmodel.h"
class HouseRoof:
	public DisplayObjectModel
{
public:
	HouseRoof(void);
	~HouseRoof(void);

	void Update(const float& t);
	void Draw();

	GLuint roof_texture_id;
};


#pragma once
#include "displayobjectmodel.h"
class HouseBody :
	public DisplayObjectModel
{
public:
	HouseBody(void);
	~HouseBody(void);

	void Update(const float& t);
	void Draw();

	GLuint housebody_texture_id;
};


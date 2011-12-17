#pragma once
#include "displayobjectmodel.h"
class HouseChemry :
	public DisplayObjectModel
{
public:
	HouseChemry(void);
	~HouseChemry(void);

	void Update(const float& t);
	void Draw();

	GLuint housechemry_texture_id;
};


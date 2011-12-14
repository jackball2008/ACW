#pragma once
#include "displayobjectmodel.h"
class Pool :
	public DisplayObjectModel
{
public:
	Pool(void);
	~Pool(void);

	void Update(const float& t);
	void Draw();

};


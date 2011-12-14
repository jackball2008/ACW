#pragma once
#include "DisplayObjectModel.h"
class Seat :
	public DisplayObjectModel
{
public:
	Seat(void);
	~Seat(void);

	void Update(const float& t);
	void Draw();
	
};


#pragma once
#include "displayobjectmodel.h"
class SeatBody :
	public DisplayObjectModel
{
public:
	SeatBody(void);
	~SeatBody(void);

	void Update(const float& t);
	void Draw();

};


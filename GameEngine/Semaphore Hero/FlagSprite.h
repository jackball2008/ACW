#pragma once
#include "gamesprite.h"
class FlagSprite :
	public GameSprite
{
public:
	FlagSprite(void);
	~FlagSprite(void);

	const float radius;

	void Draw();

	bool CheckInRange2D(const float& x,const float& y);
};


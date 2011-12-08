#pragma once
#include "gamemenuclass.h"
class SemaphoreHeroMainMenu :
	public GameMenuClass
{
public:
	SemaphoreHeroMainMenu(void);
	~SemaphoreHeroMainMenu(void);

	FontGameSprite *itemList[2];

	void Begin();

	void Draw();

	void Running();
};


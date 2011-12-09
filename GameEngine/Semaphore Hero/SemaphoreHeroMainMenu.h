#pragma once
#include "FontGameSprite.h"
#include "GameSceneClass.h"
class SemaphoreHeroMainMenu :
	public GameSceneClass
{
public:
	SemaphoreHeroMainMenu(void);
	~SemaphoreHeroMainMenu(void);

	//menu list
	int itemNum;
	FontGameSprite *itemList[2];

	void Begin();

	void Running();

	void End();

	void Draw();
};


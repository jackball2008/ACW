#pragma once
#include "gamesceneclass.h"
#include "SkeletonGameSprite.h"
#include "FontGameSprite.h"
#include "FlagSprite.h"

class SemaphoreHeroGameSceneClass :
	public GameSceneClass
{
public:
	SemaphoreHeroGameSceneClass(void);
	~SemaphoreHeroGameSceneClass(void);

	/************************************************************************/
	/* store all materials in here                                                                     */
	/************************************************************************/
	void Begin();
	void Running();
	void End();
	void Draw();

	SkeletonGameSprite skeletonPlayer;
	//override
	void SetInputManager(IInputManager*);

	//for display word
	int itemNum;
	FontGameSprite *itemList[4];
	FontGameSprite* questionLabel;
	FontGameSprite* answerLabel;
	FontGameSprite* timerLabel;
	FontGameSprite* scoreLabel;

	//for flag
	FlagSprite* leftFlag;
	FlagSprite* rightFlag;


	//for position calculation



};


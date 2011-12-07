#pragma once
#include "gamesceneclass.h"
#include "SkeletonGameSprite.h"

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

};


#pragma once
#include "gamesceneclass.h"
#include "FlagSprite.h"
class TestScene :
	public GameSceneClass
{
public:
	TestScene(void);
	TestScene(const int& rt);
	~TestScene(void);


	void Begin();
	void Running();
	void End();
	void Draw();

	//override
	void SetInputManager(IInputManager*);

	//skeleton man sprite
	SkeletonGameSprite *skeletonPlayer;

	//flag sprite
	FlagSprite* leftFlag;
	FlagSprite* rightFlag;
};


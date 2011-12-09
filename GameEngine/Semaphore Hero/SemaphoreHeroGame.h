#pragma once
#include "VideoGameClass.h"
#include "BasicRenderManager.h"
#include "KinectInputManager.h"
#include "SemaphoreHeroGameSceneManager.h"
#include "SemaphoreHeroGameSceneClass.h"
#include "SemaphoreHeroMainMenu.h"
#include "LetterGameSceneClass.h"


class SemaphoreHeroGame : public VideoGameClass
{
public:
	SemaphoreHeroGame(void);
	~SemaphoreHeroGame(void);


	void Initialize(HWND hwnd,int w,int hei,int type);
	void RunGameLogic();

	//release kinect device resource
	void WM_DestoryHandler();

	IGameSceneClass* gameMainMenu;

	//play
	IGameSceneClass* semaphoreHeroGameScene;
	IGameSceneClass* letterGameScene;
};


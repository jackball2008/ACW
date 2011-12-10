#pragma once
#include "VideoGameClass.h"
#include "BasicRenderManager.h"
#include "KinectInputManager.h"
#include "SemaphoreHeroGameSceneClass.h"
#include "TestScene.h"
#include "BasicSceneManager.h"
#include "DirectXBasicRenderManager.h"

class SemaphoreHeroGame : public VideoGameClass
{
public:
	SemaphoreHeroGame(void);
	~SemaphoreHeroGame(void);


	void Initialize(HWND hwnd,int w,int hei);
	void RunGameLogic();

	//release kinect device resource
	void WM_DestoryHandler();

	IGameSceneClass* testScene;

	
};


#pragma once
#include "VideoGameClass.h"
#include "BasicAssetManager.h"
#include "BasicInputManager.h"
#include "BasicRenderManager.h"
//#include "BasicSceneManager.h"
#include "BasicScriptManager.h"
#include "KinectInputManager.h"
#include "SemaphoreHeroGameSceneManager.h"
#include "GameMenuClass.h"
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

	
	/************************************************************************/
	/* initialize main menu                                                                     */
	/************************************************************************/
	/*GameMenuClass* gameMainMenu;*/

	SemaphoreHeroMainMenu* gameMainMenu;

	//play
	SemaphoreHeroGameSceneClass* playScene;
	LetterGameSceneClass* firstScene;
};


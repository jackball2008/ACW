#include "SemaphoreHeroGame.h"


SemaphoreHeroGame::SemaphoreHeroGame(void)
{
}


SemaphoreHeroGame::~SemaphoreHeroGame(void)
{
	
}

void SemaphoreHeroGame::Initialize(HWND hwnd,int w,int hei,int type){
	
	renderManager = new BasicRenderManager();
	renderManager->InitializeOpenGL(hwnd, w, hei);
	
	inputManager = new KinectInputManager();
	sceneManager = new SemaphoreHeroGameSceneManager();
	
	//bind
	sceneManager->SetInputManager(inputManager);
	sceneManager->SetRenderManager(renderManager);

	//scene setting
	//menu
	gameMainMenu = new GameMenuClass();
	sceneManager->SetMainMenu(gameMainMenu);
	gameMainMenu->SetInputManager(inputManager);
	/***/
	//play
	playScene = new SemaphoreHeroGameSceneClass();
	playScene->SetInputManager(inputManager);
// 	SkeletonGameSprite *sp = &(playScene->skeletonPlayer);
// 	inputManager->SetSkeletonDataOuptTarget(sp);
	sceneManager->SetPlayScene(playScene);
	//initkinect
	inputManager->Initialize();
}

void SemaphoreHeroGame::RunGameLogic(){
	switch(currentState){
	case CHOOSEMENU:
		sceneManager->RunChooseMenu(&currentState);
		break;
	case GAMEPLAYING:
		sceneManager->RunGamePlaying(&currentState);
		break;
	case SHOWSCORE:
		sceneManager->RunShowScore(&currentState);
		break;
	case GAMEEXIT:
		sceneManager->RunGameExit(&currentState);
		break;
	}
}

void SemaphoreHeroGame::WM_DestoryHandler(){
	delete (KinectInputManager*)inputManager;
}

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
	/*gameMainMenu = new GameMenuClass();*/
	gameMainMenu = new SemaphoreHeroMainMenu();
	//sceneManager->SetMainMenu(gameMainMenu);
	gameMainMenu->SetInputManager(inputManager);
	gameMainMenu->Begin();
	/***/
	//play
	semaphoreHeroGameScene = new SemaphoreHeroGameSceneClass();
	semaphoreHeroGameScene->SetInputManager(inputManager);
	semaphoreHeroGameScene->Begin();
// 	SkeletonGameSprite *sp = &(playScene->skeletonPlayer);
// 	inputManager->SetSkeletonDataOuptTarget(sp);
	//sceneManager->SetPlayScene(playScene);
	letterGameScene = new LetterGameSceneClass();
	letterGameScene->SetInputManager(inputManager);
	letterGameScene->Begin();
	//initkinect
	inputManager->Initialize();
}

void SemaphoreHeroGame::RunGameLogic(){
	switch(currentSceneID){
	case 0:
		//sceneManager->RunChooseMenu(&currentState);
		sceneManager->PlayScene(gameMainMenu,&currentSceneID);
		break;
	case 1:
		//sceneManager->RunGamePlaying(&currentState);
		sceneManager->PlayScene(letterGameScene,&currentSceneID);
		break;
	case 2:
		//sceneManager->RunShowScore(&currentState);
		sceneManager->PlayScene(semaphoreHeroGameScene,&currentSceneID);
		break;
	
	}
}

void SemaphoreHeroGame::WM_DestoryHandler(){
	delete (KinectInputManager*)inputManager;
}

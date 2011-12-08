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
	sceneManager->SetMainMenu(gameMainMenu);
	gameMainMenu->SetInputManager(inputManager);
	//gameMainMenu->Begin();
	/***/
	//play
	playScene = new SemaphoreHeroGameSceneClass();
	playScene->SetInputManager(inputManager);
	playScene->Begin();
// 	SkeletonGameSprite *sp = &(playScene->skeletonPlayer);
// 	inputManager->SetSkeletonDataOuptTarget(sp);
	//sceneManager->SetPlayScene(playScene);
	firstScene = new LetterGameSceneClass();
	firstScene->SetInputManager(inputManager);
	firstScene->Begin();
	//initkinect
	inputManager->Initialize();
}

void SemaphoreHeroGame::RunGameLogic(){
	switch(currentState){
	case 0:
		//sceneManager->RunChooseMenu(&currentState);
		sceneManager->PlayScene(gameMainMenu,&currentState);
		break;
	case 1:
		//sceneManager->RunGamePlaying(&currentState);
		sceneManager->PlayScene(firstScene,&currentState);
		break;
	case 2:
		//sceneManager->RunShowScore(&currentState);
		sceneManager->PlayScene(playScene,&currentState);
		break;
	
	}
}

void SemaphoreHeroGame::WM_DestoryHandler(){
	delete (KinectInputManager*)inputManager;
}

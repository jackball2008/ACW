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
	sceneManager = new BasicSceneManager();
	
	//bind
	sceneManager->SetInputManager(inputManager);
	sceneManager->SetRenderManager(renderManager);

	//scene setting
	//menu
	gameMainMenu = new SemaphoreHeroMainMenu();
	gameMainMenu->SetInputManager(inputManager);
	gameMainMenu->Begin();
	
	//play
	semaphoreHeroGameScene = new SemaphoreHeroGameSceneClass();
	semaphoreHeroGameScene->SetInputManager(inputManager);
	semaphoreHeroGameScene->Begin();

	letterGameScene = new LetterGameSceneClass();
	letterGameScene->SetInputManager(inputManager);
	letterGameScene->Begin();
	//initkinect
	inputManager->Initialize();
}

void SemaphoreHeroGame::RunGameLogic(){
	switch(currentSceneID){
	case 0:
		sceneManager->PlayScene(gameMainMenu,&currentSceneID);
		break;
	case 1:
		sceneManager->PlayScene(letterGameScene,&currentSceneID);
		break;
	case 2:
		sceneManager->PlayScene(semaphoreHeroGameScene,&currentSceneID);
		break;
	
	}
}

void SemaphoreHeroGame::WM_DestoryHandler(){
	delete (KinectInputManager*)inputManager;
}

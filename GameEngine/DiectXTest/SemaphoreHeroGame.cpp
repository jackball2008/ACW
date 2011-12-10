#include "SemaphoreHeroGame.h"


SemaphoreHeroGame::SemaphoreHeroGame(void)
{
}


SemaphoreHeroGame::~SemaphoreHeroGame(void)
{
	
}

void SemaphoreHeroGame::Initialize(HWND hwnd,int w,int hei){
	
	renderManager = new DirectXBasicRenderManager();
	
	renderManager->InitializeISceneRender(hwnd, w, hei);
	
	

	inputManager = new KinectInputManager();
	sceneManager = new BasicSceneManager();
	
	//bind
	sceneManager->SetInputManager(inputManager);
	sceneManager->SetRenderManager(renderManager);

	testScene = new TestScene();
	
	testScene->SetInputManager(inputManager);
	testScene->Begin();

	
	//initkinect
	inputManager->Initialize();
}

void SemaphoreHeroGame::RunGameLogic(){

 	sceneManager->PlayScene(testScene,&currentSceneID);

}

void SemaphoreHeroGame::WM_DestoryHandler(){
	delete (KinectInputManager*)inputManager;
}

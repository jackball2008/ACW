#include "SemaphoreHeroGame.h"


SemaphoreHeroGame::SemaphoreHeroGame(void)
{
}


SemaphoreHeroGame::~SemaphoreHeroGame(void)
{
	
}

void SemaphoreHeroGame::Initialize(HWND hwnd,int w,int hei,int type){
	
	renderManager = new BasicRenderManager();
	//renderManager->InitializeOpenGL(hwnd, w, hei);
	renderManager->InitializeRenderSys(hwnd, w, hei,type);
	
	

	inputManager = new KinectInputManager();
	sceneManager = new BasicSceneManager();
	
	//bind
	sceneManager->SetInputManager(inputManager);
	sceneManager->SetRenderManager(renderManager);

	testScene = new TestScene(type);
	//testScene->SetRenderType(type);
	testScene->SetInputManager(inputManager);
	testScene->Begin();

	
	//initkinect
	inputManager->Initialize();
}

void SemaphoreHeroGame::RunGameLogic(){
	//renderManager->RenderDX();
// 	switch(currentSceneID){
// 	case 0:
 		sceneManager->PlayScene(testScene,&currentSceneID);
// 		break;
// 	}
}

void SemaphoreHeroGame::WM_DestoryHandler(){
	delete (KinectInputManager*)inputManager;
}

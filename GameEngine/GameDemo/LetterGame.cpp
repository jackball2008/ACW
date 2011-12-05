#include "LetterGame.h"


LetterGame::LetterGame(void)
{
}


LetterGame::~LetterGame(void)
{
}

void LetterGame::Initialize(HWND hwnd,int w,int hei,int type){
	renderManager = new BasicRenderManager();
	renderManager->InitializeOpenGL(hwnd, w, hei);
	assetManager = new BasicAssetManager();
	inputManager = new BasicInputManager();
	scriptManager = new BasicScriptManager();
	sceneManager = new BasicSceneManager();
	//bind
	sceneManager->SetAssetManager(assetManager);
	sceneManager->SetInputManager(inputManager);
	sceneManager->SetRenderManager(renderManager);
	sceneManager->SetScriptManager(scriptManager);
	//menu
	gameMainMenu = new GameMenuClass();
	sceneManager->SetMainMenu(gameMainMenu);
	gameMainMenu->SetInputManager(inputManager);
	//play
	LetterGameSceneClass* playScene = new LetterGameSceneClass();
	sceneManager->SetPlayScene(playScene);
	playScene->SetInputManager(inputManager);


}
void LetterGame::RunGameLogic(){
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

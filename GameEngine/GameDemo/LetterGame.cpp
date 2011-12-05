#include "LetterGame.h"


LetterGame::LetterGame(void)
{
}


LetterGame::~LetterGame(void)
{
}

void LetterGame::Initialize(){
	assetManager = new BasicAssetManager();
	inputManager = new BasicInputManager();
	renderManager = new BasicRenderManager();
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
	//play
	LetterGameSceneClass* playScene = new LetterGameSceneClass();
	playScene->SetInputManager(inputManager);
	sceneManager->SetPlayScene(playScene);


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

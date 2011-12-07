#include "BasicSceneManager.h"


BasicSceneManager::BasicSceneManager(void):_hasAssetManager(false),_hasInputManager(false),_hasRenderManager(false),_hasScriptManager(false)
{
}


BasicSceneManager::~BasicSceneManager(void)
{
}

void BasicSceneManager::Initialize(){
	
}

void BasicSceneManager::SetAssetManager(IAssetManager* am){
	_assetManager = am;
	_hasAssetManager = true;
}

void BasicSceneManager::SetInputManager(IInputManager* im){
	_inputManager = im;
	_hasInputManager = true;
}

void BasicSceneManager::SetRenderManager(IRenderManager* rm){
	_renderManager = rm;
	_hasRenderManager = true;
}

void BasicSceneManager::SetScriptManager(IScriptManager* sm){
	_scriptManager = sm;
	_hasScriptManager = true;
}



/************************************************************************/
/* Game state running callback                                                                    */
/************************************************************************/
//CHOOSEMENU
void BasicSceneManager::RunChooseMenu(int* gs){
	_renderManager->RenderOpenGL(mainMenu);
	key = _inputManager->GetvKeyValue();
	mainMenu->SetStopSceneFlag(gs);
	switch(key){
	case '1':
		_inputManager->RecovervKey();
		//play
		*gs = GAMEPLAYING;
		mainMenu->End();
		break;
	case '2':
		//load
		*gs = LOADSAVE;
		_inputManager->RecovervKey();
		break;
	case '3':
		//score
		*gs = SHOWSCORE;
		_inputManager->RecovervKey();
		break;
	case '4':
		//exit
		*gs = GAMEEXIT;
		_inputManager->RecovervKey();
		break;
	}

}
//GAMEPLAYING
void BasicSceneManager::RunGamePlaying(int* gs){
	playScene->SetStopSceneFlag(gs);
	playScene->Running();
	_renderManager->RenderOpenGL(playScene);

}
//SHOWSCORE
void BasicSceneManager::RunShowScore(int* gs){

}
//GAMEEXIT
void BasicSceneManager::RunGameExit(int* gs){

}


/************************************************************************/
/* Main Menu                                                                     */
/************************************************************************/
void BasicSceneManager::SetMainMenu(GameMenuClass* m){
	mainMenu = m;
	mainMenu->Begin();
}
void BasicSceneManager::SetPlayScene(IGameSceneClass* scene){
	playScene = scene;
	playScene->Begin();
}
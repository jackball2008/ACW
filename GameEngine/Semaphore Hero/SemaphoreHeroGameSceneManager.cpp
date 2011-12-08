#include "SemaphoreHeroGameSceneManager.h"


SemaphoreHeroGameSceneManager::SemaphoreHeroGameSceneManager(void)
{
}


SemaphoreHeroGameSceneManager::~SemaphoreHeroGameSceneManager(void)
{
}


//GAMEPLAYING
void SemaphoreHeroGameSceneManager::RunGamePlaying(int* gs){
	playScene->SetStopSceneFlag(gs);
	playScene->Running();
	_renderManager->RenderOpenGL(playScene);
}
//choose main menu
void SemaphoreHeroGameSceneManager::RunChooseMenu(int* gs){
	_renderManager->RenderOpenGL(mainMenu);
	key = _inputManager->GetvKeyValue();
	switch(key){
		case '1':
		_inputManager->RecovervKey();
		mainMenu->End();
		*gs = 1;
		break;
	case '2':
		_inputManager->RecovervKey();
		mainMenu->End();
		*gs = 2;
		break;

	}
}

//SHOWSCORE
//void SemaphoreHeroGameSceneManager::RunShowScore(int* gs){}
//GAMEEXIT
//void SemaphoreHeroGameSceneManager::RunGameExit(int* gs){}
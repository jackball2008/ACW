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

//SHOWSCORE
void SemaphoreHeroGameSceneManager::RunShowScore(int* gs){}
//GAMEEXIT
void SemaphoreHeroGameSceneManager::RunGameExit(int* gs){}
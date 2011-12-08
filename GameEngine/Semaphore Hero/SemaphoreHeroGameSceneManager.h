#pragma once
#include "basicscenemanager.h"

class SemaphoreHeroGameSceneManager :
	public BasicSceneManager
{
public:
	SemaphoreHeroGameSceneManager(void);
	~SemaphoreHeroGameSceneManager(void);


 	void RunGamePlaying(int* gs);
 	void RunShowScore(int* gs);
 	void RunGameExit(int* gs);
};

#pragma once
#include "basicscenemanager.h"
class GameSceneManager :
	public BasicSceneManager
{
public:
	GameSceneManager(void);
	~GameSceneManager(void);

	void Initialize();
	//setter imanager

	void MainLoop();
};


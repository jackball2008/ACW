#pragma once
#include "basicscenemanager.h"
class GameSceneManager :
	public BasicSceneManager
{
public:
	GameSceneManager(void);
	~GameSceneManager(void);




	void OperateCurrentGameScene(bool *con);
	//begin
	void CreateCurrentSceneEnvironment();
	//play
	void RunningGameInCurrentSceneEnvironment();
	//end operation
	void EndCurrentSceneEnvironment();
};


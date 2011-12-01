#pragma once
#include "basicscenemanager.h"
#include "LetterGameSceneClass.h"

typedef void(*tp)();

struct TestS{
	tp p;
};


class GameSceneManager :
	public BasicSceneManager
{
public:
	GameSceneManager(void);
	~GameSceneManager(void);

	/************************************************************************/
	/* main logic override basic manager's method                                                                     */
	/************************************************************************/
	void OperateCurrentGameScene(bool *con);
	//begin
	void CreateCurrentSceneEnvironment();
	//play
	void RunningGameInCurrentSceneEnvironment();
	//end operation
	void EndCurrentSceneEnvironment();

	/************************************************************************/
	/* Letter Game Elements                                                                     */
	/************************************************************************/
	LetterGameSceneClass* currentScene;
// 	TestS *tc;
// 	void (*p)();
// 	
// 
// 	void test();

};


#include "GameSceneManager.h"


GameSceneManager::GameSceneManager(void)
{
}


GameSceneManager::~GameSceneManager(void)
{
}


void GameSceneManager::OperateCurrentGameScene(bool *con){
	std::cout<<"GameSceneManager::OperateCurrentGameScene"<<endl;
	CreateCurrentSceneEnvironment();
	RunningGameInCurrentSceneEnvironment();
	EndCurrentSceneEnvironment();
	*con = false;
}

//begin create
void GameSceneManager::CreateCurrentSceneEnvironment(){
	std::cout<<"GameSceneManager::CreateCurrentSceneEnvironment"<<endl;
	currentScene = new LetterGameSceneClass();
	//tc = new TestS;
	//*tc.p = &EndCurrentSceneEnvironment;
	//p = &EndCurrentSceneEnvironment;
}
//play
void GameSceneManager::RunningGameInCurrentSceneEnvironment(){
	std::cout<<"GameSceneManager::RunningGameInCurrentSceneEnvironment"<<endl;


}
//end operation
void GameSceneManager::EndCurrentSceneEnvironment(){
	std::cout<<"GameSceneManager::EndCurrentSceneEnvironment"<<endl;
}

// void GameSceneManager::test(){
// 	std::cout<<"tttt"<<endl;
// }

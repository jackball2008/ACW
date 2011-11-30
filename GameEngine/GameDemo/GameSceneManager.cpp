#include "GameSceneManager.h"


GameSceneManager::GameSceneManager(void)
{
}


GameSceneManager::~GameSceneManager(void)
{
}


void GameSceneManager::OperateCurrentGameScene(bool *con){
	std::cout<<"GameSceneManager::OperateCurrentGameScene"<<endl;

	BasicScriptManager:OperateCurrentGameScene(con);
	*con = false;
}
//begin
void GameSceneManager::CreateCurrentSceneEnvironment(){

}
//play
void GameSceneManager::RunningGameInCurrentSceneEnvironment(){

}
//end operation
void GameSceneManager::EndCurrentSceneEnvironment(){

}

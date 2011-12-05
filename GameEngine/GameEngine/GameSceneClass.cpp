#include "GameSceneClass.h"


GameSceneClass::GameSceneClass(void)
{
}


GameSceneClass::~GameSceneClass(void)
{
}


void GameSceneClass::Begin(){

}
void GameSceneClass::Running(){

}
void GameSceneClass::End(){

}
void GameSceneClass::SetNextScene(IGameSceneClass* g){
	nextGameScene = g;
}
IGameSceneClass* GameSceneClass::GetNextScene(){
	return nextGameScene;
}

void GameSceneClass::Draw(){

}

void GameSceneClass::SetInputManager(IInputManager* m){
	inputManager = m;
}
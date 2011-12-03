#include "GameMenuClass.h"


GameMenuClass::GameMenuClass(void)
{
	hasStartScene = false;
	hasLoadScene = false;
	hasScoreScene = false;
	hasExitScene = false;
}


GameMenuClass::~GameMenuClass(void)
{
}

void GameMenuClass::SetStartScene(IGameSceneClass* c){
	startScene = c;
	hasStartScene = true;
}
void GameMenuClass::SetLoadScene(IGameSceneClass* c){
	loadScene = c;
	hasLoadScene = true;
}
void GameMenuClass::SetScoreScene(IGameSceneClass* c){
	scoreScene = c;
	hasScoreScene = true;
}
void GameMenuClass::SetExitScene(IGameSceneClass* c){
	exitScene = c;
	hasExitScene = true;
}

void GameMenuClass::ChooseStartItem(){
	
}
void GameMenuClass::ChooseLoadItem(){

}
void GameMenuClass::ChooseScoreItem(){

}
void GameMenuClass::ChooseExitItem(){

}
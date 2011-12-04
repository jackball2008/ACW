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
//////////////////////////////////////////////////////////////////////////
void GameMenuClass::Begin(){
	itemNum = 4;

	itemList[0] = new FontGameSprite();
	itemList[1] = new FontGameSprite();
	itemList[2] = new FontGameSprite();
	itemList[3] = new FontGameSprite();
	//menuList[0] start
	itemList[0]->letter = "1.START";
	itemList[0]->color3f.x = 1.0;
	itemList[0]->pos3f.x = -0.1;
	itemList[0]->pos3f.y = 0.2;
	itemList[0]->num = 1;
	itemList[0]->BuildFont();

	itemList[1]->letter = "2.LOAD";
	itemList[1]->color3f.y = 1.0;
	itemList[1]->pos3f.x = -0.1;
	itemList[1]->pos3f.y = 0.1;
	itemList[1]->num = 2;
	itemList[1]->BuildFont();

	itemList[2]->letter = "3.SCORE";
	itemList[2]->color3f.z = 1.0;
	itemList[2]->pos3f.x = -0.1;
	itemList[2]->pos3f.y = -0.1;
	itemList[2]->num = 3;
	itemList[2]->BuildFont();

	itemList[3]->letter = "4.EXIT";
	itemList[3]->color3f.x = 1.0;
	itemList[3]->color3f.y = 1.0;
	itemList[3]->color3f.z = 1.0;
	itemList[3]->pos3f.x = -0.1;
	itemList[3]->pos3f.y = -0.2;
	itemList[3]->num = 4;
	itemList[3]->BuildFont();


}
void GameMenuClass::Running(){

}
void GameMenuClass::End(){

}

void GameMenuClass::Draw(){
	for(int i=0;i<itemNum;i++){
		glColor3f(itemList[i]->color3f.x,itemList[i]->color3f.y,itemList[i]->color3f.z);
		glRasterPos2f(itemList[i]->pos3f.x,itemList[i]->pos3f.y);
		itemList[i]->Draw();
	}
}
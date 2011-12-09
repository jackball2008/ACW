#include "SemaphoreHeroMainMenu.h"


SemaphoreHeroMainMenu::SemaphoreHeroMainMenu(void)
{
}


SemaphoreHeroMainMenu::~SemaphoreHeroMainMenu(void)
{
}

void SemaphoreHeroMainMenu::Begin(){

	itemNum = 2;

	itemList[0] = new FontGameSprite();
	itemList[1] = new FontGameSprite();

	//menuList[0] start
	itemList[0]->letter = "1 START WORD GAME";
	itemList[0]->color3f.x = 1.0;
	itemList[0]->pos3f.x = -0.1;
	itemList[0]->pos3f.y = 0.2;
	itemList[0]->num = 1;
	itemList[0]->BuildFont();

	itemList[1]->letter = "2 START KINECT GAME";
	itemList[1]->color3f.y = 1.0;
	itemList[1]->pos3f.x = -0.1;
	itemList[1]->pos3f.y = 0.1;
	itemList[1]->num = 2;
	itemList[1]->BuildFont();


}

void SemaphoreHeroMainMenu::Running(){
	char key = inputManager->GetvKeyValue();
	switch(key){
		case '1':
		inputManager->RecovervKey();
		End();
		*nextSceneFlag = 1;
		break;
	case '2':
		inputManager->RecovervKey();
		End();
		*nextSceneFlag = 2;
		break;

	}

}

void SemaphoreHeroMainMenu::End(){}


void SemaphoreHeroMainMenu::Draw(){
	glPushMatrix();
	glTranslatef(0.0f,0.0f,-1.0f);

	for(int i=0;i<itemNum;i++){
		glColor3f(itemList[i]->color3f.x,itemList[i]->color3f.y,itemList[i]->color3f.z);
		glRasterPos2f(itemList[i]->pos3f.x,itemList[i]->pos3f.y);
		itemList[i]->Draw();
	}
	glPopMatrix();
}
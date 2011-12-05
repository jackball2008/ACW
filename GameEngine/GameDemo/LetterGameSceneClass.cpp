#include "LetterGameSceneClass.h"

const char letterArray[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
LetterGameSceneClass::LetterGameSceneClass(void)
{
	isStart = true;
	isGameOver = false;
}


LetterGameSceneClass::~LetterGameSceneClass(void)
{
}

void LetterGameSceneClass::Begin(){
	itemNum = 4;

	itemList[0] = new FontGameSprite();
	itemList[1] = new FontGameSprite();
	itemList[2] = new FontGameSprite();
	itemList[3] = new FontGameSprite();

	itemList[0]->letter = "Question";
	/*itemList[0]->displayNum = 99;*/
	itemList[0]->color3f.x = 1.0;
	itemList[0]->color3f.y = 1.0;
	itemList[0]->color3f.z = 1.0;
	itemList[0]->pos3f.x = -0.1;
	itemList[0]->pos3f.y = 0.2;
	itemList[0]->num = 1;
	itemList[0]->BuildFont();

	itemList[1]->letter = "Answer";
	itemList[1]->color3f.x = 1.0;
	itemList[1]->color3f.y = 1.0;
	itemList[1]->color3f.z = 1.0;
	itemList[1]->pos3f.x = -0.1;
	itemList[1]->pos3f.y = 0.1;
	itemList[1]->num = 2;
	itemList[1]->BuildFont();

	itemList[2]->letter = "Time : %d";
	itemList[2]->displayNum = 5;
	itemList[2]->color3f.x = 1.0;
	itemList[2]->color3f.y = 1.0;
	itemList[2]->color3f.z = 1.0;
	itemList[2]->pos3f.x = -0.1;
	itemList[2]->pos3f.y = -0.1;
	itemList[2]->num = 3;
	itemList[2]->BuildFont();

	itemList[3]->letter = "Score";
	itemList[3]->color3f.x = 1.0;
	itemList[3]->color3f.y = 1.0;
	itemList[3]->color3f.z = 1.0;
	itemList[3]->pos3f.x = -0.1;
	itemList[3]->pos3f.y = -0.2;
	itemList[3]->num = 4;
	itemList[3]->BuildFont();

	question = itemList[0];
	answer = itemList[1];
	timer = itemList[2];
	score = itemList[3];


}
void LetterGameSceneClass::Running(){
	//logic here
	if(isStart){
		isStart = false;
		startTime = GetTickCount();
	}
	stopTime = GetTickCount();
	timerDelta = stopTime - startTime;
	if(timerDelta>=1000){
		timer->displayNum--;
		timerDelta = 0;
		startTime = stopTime;
	}
	
	if(timer->displayNum == 0){
		End();
	}


}
void LetterGameSceneClass::End(){
	isStart = true;
	startTime = 0;
	stopTime = 0;
	timerDelta = 0;
	timer->displayNum =  5;
	*stopflag = 0;
}
void LetterGameSceneClass::Draw(){


	glPushMatrix();
	glTranslatef(0.0f,0.0f,-1.0f);


	for(int i=0;i<itemNum;i++){
		glColor3f(itemList[i]->color3f.x,itemList[i]->color3f.y,itemList[i]->color3f.z);
		glRasterPos2f(itemList[i]->pos3f.x,itemList[i]->pos3f.y);
		itemList[i]->Draw();
	}

	glPopMatrix();
}
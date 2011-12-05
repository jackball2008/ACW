#include "LetterGameSceneClass.h"


LetterGameSceneClass::LetterGameSceneClass(void)
{
	
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

	itemList[2]->letter = "Time";
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


}
void LetterGameSceneClass::Running(){

}
void LetterGameSceneClass::End(){

}
void LetterGameSceneClass::Draw(){





	for(int i=0;i<itemNum;i++){
		glColor3f(itemList[i]->color3f.x,itemList[i]->color3f.y,itemList[i]->color3f.z);
		glRasterPos2f(itemList[i]->pos3f.x,itemList[i]->pos3f.y);
		itemList[i]->Draw();
	}
}
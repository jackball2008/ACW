#include "LetterGameSceneClass.h"


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
	
	itemList[0]->color3f.x = 1.0;
	itemList[0]->color3f.y = 1.0;
	itemList[0]->color3f.z = 1.0;
	itemList[0]->pos3f.x = -0.1f;
	itemList[0]->pos3f.y = 0.2f;
	itemList[0]->num = 1;
	itemList[0]->BuildFont();

	itemList[1]->letter = "Answer";
	itemList[1]->color3f.x = 1.0;
	itemList[1]->color3f.y = 1.0;
	itemList[1]->color3f.z = 1.0;
	itemList[1]->pos3f.x = -0.1f;
	itemList[1]->pos3f.y = 0.1f;
	itemList[1]->num = 2;
	itemList[1]->BuildFont();

	itemList[2]->letter = "Time : %d";
	itemList[2]->displayNum = GAMELENGTH;
	itemList[2]->color3f.x = 1.0;
	itemList[2]->color3f.y = 1.0;
	itemList[2]->color3f.z = 1.0;
	itemList[2]->pos3f.x = -0.1f;
	itemList[2]->pos3f.y = -0.1f;
	itemList[2]->num = 3;
	itemList[2]->BuildFont();

	itemList[3]->letter = "Score";
	itemList[3]->color3f.x = 1.0;
	itemList[3]->color3f.y = 1.0;
	itemList[3]->color3f.z = 1.0;
	itemList[3]->pos3f.x = -0.1f;
	itemList[3]->pos3f.y = -0.2f;
	itemList[3]->num = 4;
	itemList[3]->BuildFont();

	question = itemList[0];
	answer = itemList[1];
	timer = itemList[2];
	score = itemList[3];

	index = 0;
	oldIndex = 0;
	isNewRand = false;

	isNewCheck = false;
	inputanswer = 1;
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
	//////////////////////////////////////////////////////////////////////////

	while(!isNewRand){
		srand((unsigned)time(0));
		index = rand()%26;
		if(index!=oldIndex)
			isNewRand = true;
	}
	if(isNewRand){
		oldIndex = index;
		DisplayQuestion(index);
		
		if(!isNewCheck){
			startAnswerTime = GetTickCount();
			isNewCheck = true;
		}
	}

	
	UINT c = inputManager->GetKeyValue();

	DisplayAnswer(c);

	if(c == matchv){
		answerRightTime = GetTickCount();
		answer->letter = "Waitting Input...";
		isNewCheck = false;
		isNewRand = false;


		CalculateResult();


	}
	else{

	}


	//////////////////////////////////////////////////////////////////////////

	if(timer->displayNum == 0){
		End();
	}


}
void LetterGameSceneClass::CalculateResult(){
	screResTime = answerRightTime - startAnswerTime;
	int k = screResTime/1000;
	if(k>5){
		score->letter = "You are so .... bad";
	}else{
		switch(k){
		case 1:
			score->letter = "Great";
			break;;
		case 2:
			score->letter = "A litter good";
			break;
		case 3:
			score->letter = "Common";
			break;
		case 4:
			score->letter = "Bad";
			break;
		case 5:
			score->letter = "Too Bad";
			break;
		}
	}
	

}
void LetterGameSceneClass::DisplayAnswer(UINT& index){
	switch(index){
	case 65:
		answer->letter = "a";
		break;
	case 66:
		answer->letter = "b";
		break;

	case 67:
		answer->letter = "c";
		break;

	case 68:
		answer->letter = "d";
		break;

	case 69:
		answer->letter = "e";
		break;
	case 70:
		answer->letter = "f";
		break;
	case 71:
		answer->letter = "g";
		break;
	case 72:
		answer->letter = "h";
		break;
	case 73:
		answer->letter = "i";
		break;
	case 74:
		answer->letter = "j";
		break;
	case 75:
		answer->letter = "k";
		break;
	case 76:
		answer->letter = "l";
		break;
	case 77:
		answer->letter = "m";
		break;
	case 78:
		answer->letter = "n";
		break;
	case 79:
		answer->letter = "o";
		break;
	case 80:
		answer->letter = "p";
		break;
	case 81:
		answer->letter = "q";
		break;
	case 82:
		answer->letter = "r";
		break;
	case 83:
		answer->letter = "s";
		break;
	case 84:
		answer->letter = "t";
		break;
	case 85:
		answer->letter = "u";
		break;
	case 86:
		answer->letter = "v";
		break;
	case 87:
		answer->letter = "w";
		break;
	case 88:
		answer->letter = "x";
		break;
	case 89:
		answer->letter = "y";
		break;
	case 90:
		answer->letter = "z";
		break;


	}
}
void LetterGameSceneClass::DisplayQuestion(int& index){
	switch(index){
	case 0:
		question->letter = "Question : a";
		matchv = index + 65;
		break;
	case 1:
		question->letter = "Question : b";
		matchv = index + 65;
		break;
	case 2:
		question->letter = "Question : c";
		matchv = index + 65;
		break;
	case 3:
		question->letter = "Question : d";
		matchv = index + 65;
		break;
	case 4:
		question->letter = "Question : e";
		matchv = index + 65;
		break;
	case 5:
		question->letter = "Question : f";
		matchv = index + 65;
		break;
	case 6:
		question->letter = "Question : g";
		matchv = index + 65;
		break;
	case 7:
		question->letter = "Question : h";
		matchv = index + 65;
		break;
	case 8:
		question->letter = "Question : i";
		matchv = index + 65;
		break;
	case 9:
		question->letter = "Question : j";
		matchv = index + 65;
		break;
	case 10:
		question->letter = "Question : k";
		matchv = index + 65;
		break;
	case 11:
		question->letter = "Question : l";
		matchv = index + 65;
		break;
	case 12:
		question->letter = "Question : m";
		matchv = index + 65;
		break;
	case 13:
		question->letter = "Question : n";
		matchv = index + 65;
		break;
	case 14:
		question->letter = "Question : o";
		matchv = index + 65;
		break;
	case 15:
		question->letter = "Question : p";
		matchv = index + 65;
		break;
	case 16:
		question->letter = "Question : q";
		matchv = index + 65;
		break;
	case 17:
		question->letter = "Question : r";
		matchv = index + 65;
		break;
	case 18:
		question->letter = "Question : s";
		matchv = index + 65;
		break;
	case 19:
		question->letter = "Question : t";
		matchv = index + 65;
		break;
	case 20:
		question->letter = "Question : u";
		matchv = index + 65;
		break;
	case 21:
		question->letter = "Question : v";
		matchv = index + 65;
		break;
	case 22:
		question->letter = "Question : w";
		matchv = index + 65;
		break;
	case 23:
		question->letter = "Question : x";
		matchv = index + 65;
		break;
	case 24:
		question->letter = "Question : y";
		matchv = index + 65;
		break;
	case 25:
		question->letter = "Question : z";
		matchv = index + 65;
		break;

	}
}
void LetterGameSceneClass::End(){
	isStart = true;
	startTime = 0;
	stopTime = 0;
	timerDelta = 0;
	timer->displayNum =  GAMELENGTH;
	
	*nextSceneFlag = 0;
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
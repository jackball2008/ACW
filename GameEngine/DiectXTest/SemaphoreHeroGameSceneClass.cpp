#include "SemaphoreHeroGameSceneClass.h"

#define FONT_HEIGHT -15


const float skeletonmanScale = 0.25;

SemaphoreHeroGameSceneClass::SemaphoreHeroGameSceneClass(void)
{
}


SemaphoreHeroGameSceneClass::~SemaphoreHeroGameSceneClass(void)
{
}

void SemaphoreHeroGameSceneClass::Begin(){
	//initialize x,y position varible
	x_left = 0;
	y_left = 0;
	x_right = 0;
	y_right = 0;
	//skeleton man color
// 	skeletonPlayer.color3f.x=1;
// 	skeletonPlayer.color3f.y =1;
// 	skeletonPlayer.color3f.z = 1;



	//left flag
	leftFlag = new FlagSprite();

	leftFlag->pos3f.x = -0.2f;
	leftFlag->pos3f.y = 0;
	leftFlag->pos3f.z = 0;

	leftFlag->color3f.x = 1;
	leftFlag->color3f.y = 0;
	leftFlag->color3f.z = 0;
	//right flag
	rightFlag = new FlagSprite();

	rightFlag->pos3f.x = 0;
	rightFlag->pos3f.y = 0.2f;
	rightFlag->pos3f.z = 0;

	rightFlag->color3f.x = 0;
	rightFlag->color3f.y = 1;
	rightFlag->color3f.z = 0;
	//timer count
	timerNum = 0;
	isStart = true;
	//core
	newSignalTime = 0;
	finishSignalTime = 0;
	scoreTime = 0;
	//question 
	questionIndex = 0;
	answerRightForCurrentQuestion = false;
	allPass = false;
	//ini flag signal
	SetSignal();


}
void SemaphoreHeroGameSceneClass::Running(){
	//timer count for display timer
// 	if(isStart == false){
// 		isStart = false;
// 		startTime = GetTickCount();
// 	}
// 	endTime = GetTickCount();
// 	deltaTime = endTime - startTime;
// 	if(deltaTime>=1000){
// 		timerNum++;
// 		timerLabel->displayNum = timerNum;
// 		startTime = endTime;
// 		deltaTime = 0;
// 	}
// 
// 	//set current signal
// 	if(questionIndex<SIGNAL_NUM){
// 		leftFlag->pos3f.x = FlagSignals[questionIndex].lx;
// 		leftFlag->pos3f.y = FlagSignals[questionIndex].ly;
// 		rightFlag->pos3f.x = FlagSignals[questionIndex].rx;
// 		rightFlag->pos3f.y = FlagSignals[questionIndex].ry;
// 		questionLabel->displayStr = FlagSignals[questionIndex].name;
// 
// 		//get new signal start time
// 		newSignalTime = GetTickCount();
// 	}
// 	
// 	/////
// 
// 	//logic 1,get hand position
// 	x_left = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_LEFT].x * skeletonmanScale;
// 	y_left = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_LEFT].y * skeletonmanScale;
// 
// 	x_right = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_RIGHT].x * skeletonmanScale;
// 	y_right = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_RIGHT].y * skeletonmanScale;
// 
// 	bool answerL = false;
// 	bool answerR = false;
// 
// 	//judge left
// 	if(leftFlag->CheckInRange2D(x_left,y_left)){
// 		leftFlag->color3f.z = 1;
// 		answerL = true;
// 	}else{
// 		leftFlag->color3f.z = 0;
// 		answerL = false;
// 	}
// 	//judge right
// 	if(rightFlag->CheckInRange2D(x_right,y_right)){
// 		rightFlag->color3f.z = 1;
// 		answerR = true;
// 	}else{
// 		rightFlag->color3f.z = 0;
// 		answerR = false;
// 	}
// 
// 	if(answerL&&answerR){
// 		//answer right
// 		answerLabel->letter = "Signal Right";
// 
// 		finishSignalTime = GetTickCount();
// 		//calculate score
// 		scoreTime = finishSignalTime - newSignalTime;
// 		int k = scoreTime/1000;
// 		if(k>5){
// 			itemList[3]->letter = "You are so .... bad";
// 		}else{
// 			switch(k){
// 			case 0:
// 				scoreLabel->letter = "Right";
// 				break;
// 			case 1:
// 				itemList[3]->letter = "Great";
// 				//scoreLabel->letter
// 				break;;
// 			case 2:
// 				itemList[3]->letter = "A litter good";
// 				break;
// 			case 3:
// 				itemList[3]->letter = "Common";
// 				break;
// 			case 4:
// 				itemList[3]->letter = "Bad";
// 				break;
// 			case 5:
// 				itemList[3]->letter = "Too Bad";
// 				break;
// 			}
// 		}
// 
// 		//end
// 
// 		questionIndex++;
// 		if(questionIndex >= SIGNAL_NUM){
// 			//current game end
// 			allPass = true;
// 			questionIndex = 0;
// 		}
// 	}
// 	else{
// 		answerLabel->letter = "Come On...";
// 	}
// 
// 	if(allPass){
// 		End();
// 	}

}
void SemaphoreHeroGameSceneClass::End(){
	//reset
	questionIndex = 0;
	answerRightForCurrentQuestion = false;
	allPass = false;
	timerNum  = 0;
	//score
	newSignalTime = 0;
	finishSignalTime = 0;
	scoreTime = 0;
	//
	*nextSceneFlag = 0;
}


void SemaphoreHeroGameSceneClass::Draw(){
	
// 	skeletonPlayer.Draw();




}
void SemaphoreHeroGameSceneClass::SetInputManager(IInputManager* in){
	inputManager = in;
	inputManager->SetSkeletonDataOuptTarget(&skeletonPlayer);
}


#define TOP_POS(x,y) x=0.0f;y=0.15f; 
#define TOPRIGHT_POS(x,y) x=y=0.13f;
#define RIGHT_POS(x,y) x=0.15f;y=0.0f;
#define BOTTOMRIGHT_POS(x,y) x=0.13f;y=-0.13f;
//
#define BOTTOM_POS(x,y) x=0.0f;y=-0.15f;
#define BOTTOMLEFT_POS(x,y) x=-0.13f;y=-0.13f;
//
#define LEFT_POS(x,y) x=-0.15f;y=0.0f;
#define TOPLEFT_POS(x,y) x=-0.13f;y=0.13f;

#define RESTL_POS(x,y) x=-0.05f;y=-0.13f;
#define RESTR_POS(x,y) x=0.05f;y=-0.13f;

void SemaphoreHeroGameSceneClass::SetSignal(){
	int i=0;
	//0
	FlagSignals[i].name = "A";
	BOTTOMLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOM_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//1
	FlagSignals[i].name = "B";
	LEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOM_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//2
	FlagSignals[i].name = "C";
	TOPLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOM_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//3
	FlagSignals[i].name = "D";
	TOP_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOM_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//4
	FlagSignals[i].name = "E";
	BOTTOM_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	TOPRIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;

	//5
	FlagSignals[i].name = "F";
	BOTTOM_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	RIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//6
	FlagSignals[i].name = "G";
	BOTTOM_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOMRIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//7
	FlagSignals[i].name = "H";
	LEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOMLEFT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//8
	FlagSignals[i].name = "I";
	TOPLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOMLEFT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//9
	FlagSignals[i].name = "J";
	TOP_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	RIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//10
	FlagSignals[i].name = "K";
	BOTTOMLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	TOP_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//11
	FlagSignals[i].name = "L";
	BOTTOMLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	TOPLEFT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//12
	FlagSignals[i].name = "M";
	BOTTOMLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	RIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//13
	FlagSignals[i].name = "N";
	BOTTOMLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOMRIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//14
	FlagSignals[i].name = "O";
	LEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	TOPLEFT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//15
	FlagSignals[i].name = "P";
	LEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	TOP_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//16
	FlagSignals[i].name = "Q";
	LEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	TOPRIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//17
	FlagSignals[i].name = "R";
	LEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	RIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//18
	FlagSignals[i].name = "S";
	LEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOMRIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//19
	FlagSignals[i].name = "T";
	TOPLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	TOP_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//20
	FlagSignals[i].name = "U";
	TOPLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	TOPRIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//21
	FlagSignals[i].name = "V";
	TOP_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOMRIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//22
	FlagSignals[i].name = "W";
	TOPRIGHT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	RIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//23
	FlagSignals[i].name = "X";
	TOPRIGHT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	BOTTOMRIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//24
	FlagSignals[i].name = "Y";
	TOPLEFT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	RIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//25
	FlagSignals[i].name = "Z";
	BOTTOMRIGHT_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	RIGHT_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
	//26
	FlagSignals[i].name = "SPAAACE";
	RESTL_POS(FlagSignals[i].lx,FlagSignals[i].ly);
	RESTR_POS(FlagSignals[i].rx,FlagSignals[i].ry);
	i++;
}
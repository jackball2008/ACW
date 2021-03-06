#pragma once
#include "GameSceneClass.h"
#include "FontGameSprite.h"
#include <iostream>
#include <ctime>

#define GAMELENGTH 60
class LetterGameSceneClass : public GameSceneClass
{
public:
	LetterGameSceneClass(void);
	~LetterGameSceneClass(void);

	/************************************************************************/
	/* store all materials in here                                                                     */
	/************************************************************************/
	void Begin();
	void Running();
	void End();
	void Draw();

	int itemNum;
	FontGameSprite *itemList[4];
	FontGameSprite* question;
	FontGameSprite* answer;
	FontGameSprite* timer;
	FontGameSprite* score;

	long startTime;
	long stopTime;
	bool isStart;
	long timerDelta;

	bool isGameOver;

	int index;
	int oldIndex;
	bool isNewRand;

	

	long startAnswerTime;
	long answerRightTime;

	char inputanswer;

	bool isNewCheck;

	UINT matchv;

	void DisplayQuestion(int&);
	void DisplayAnswer(UINT&);

	long screResTime;
	void CalculateResult();

};


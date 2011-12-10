#pragma once
#include "gamesceneclass.h"
#include "SkeletonGameSprite.h"
#include "FontGameSprite.h"
#include "FlagSprite.h"


struct FlagPos{
	char* name;
	float lx;
	float ly;
	float rx;
	float ry;
};
#define SIGNAL_NUM 27

class SemaphoreHeroGameSceneClass :
	public DirectXGameSceneClass
{
public:
	SemaphoreHeroGameSceneClass(void);
	~SemaphoreHeroGameSceneClass(void);

	/************************************************************************/
	/* store all materials in here                                                                     */
	/************************************************************************/
	void Begin();
	void Running();
	void End();
	void Draw();

	
	//override
	void SetInputManager(IInputManager*);


	//skeleton man sprite
	SkeletonGameSprite skeletonPlayer;



	//flag sprite
	FlagSprite* leftFlag;
	FlagSprite* rightFlag;


	//for position calculation
	float x_left;
	float y_left;
	float x_right;
	float y_right;

	//question index
	FlagPos FlagSignals[SIGNAL_NUM];
	void SetSignal();
	int questionIndex;
	bool answerRightForCurrentQuestion;
	bool allPass;
	//timer
	int timerNum;
	long startTime;
	long endTime;
	long deltaTime;
	bool isStart;
	//score calculation
	long newSignalTime;
	long finishSignalTime;
	long scoreTime;

};


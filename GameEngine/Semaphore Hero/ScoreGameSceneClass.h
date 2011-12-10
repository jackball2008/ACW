#pragma once
#include "gamesceneclass.h"
class ScoreGameSceneClass :
	public GameSceneClass
{
public:
	ScoreGameSceneClass(void);
	~ScoreGameSceneClass(void);


	void Begin();
	void Running();
	void End();
	void Draw();


};


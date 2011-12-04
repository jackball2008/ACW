#pragma once
#include "GameSceneClass.h"

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


};


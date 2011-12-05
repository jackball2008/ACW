#pragma once
#include "videogameclass.h"
#include "BasicAssetManager.h"
#include "BasicInputManager.h"
#include "BasicRenderManager.h"
#include "BasicSceneManager.h"
#include "BasicScriptManager.h"
#include "LetterGameSceneClass.h"

class LetterGame :
	public VideoGameClass
{
public:
	LetterGame(void);
	~LetterGame(void);

 	void Initialize();
 	void RunGameLogic();
};


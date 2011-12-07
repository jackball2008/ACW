#pragma once
#include "videogameclass.h"
#include "BasicAssetManager.h"
#include "BasicInputManager.h"
#include "BasicRenderManager.h"
#include "BasicSceneManager.h"
#include "BasicScriptManager.h"
#include "LetterGameSceneClass.h"
#include "GameMenuClass.h"

class LetterGame :
	public VideoGameClass
{
public:
	LetterGame(void);
	~LetterGame(void);

	/************************************************************************/
	/* initialize main menu                                                                     */
	/************************************************************************/
	GameMenuClass* gameMainMenu;
	//
	LetterGameSceneClass* playScene;
	GameSceneClass* scoreScene;

 	void Initialize(HWND hwnd,int w,int hei,int type);
 	void RunGameLogic();

	
};


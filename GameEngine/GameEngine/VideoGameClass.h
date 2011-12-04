#pragma once
#include "IVideoGameClass.h"
#include "ISceneManager.h"
#include "IAssetManager.h"
#include "IInputManager.h"
#include "IRenderManager.h"
#include "IScriptManager.h"
//#include "GameStateDefine.h"
#include "GameMenuClass.h"


#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

/************************************************************************/
/* Game State     List                                                         */
/************************************************************************/
enum GameRunningState{CHOOSEMENU,GAMEPLAYING,SHOWSCORE,GAMEEXIT};


class VideoGameClass : public IVideoGameClass
{
public:
	__declspec(DLL_OUTPUT) VideoGameClass(void);
	__declspec(DLL_OUTPUT) ~VideoGameClass(void);

	/************************************************************************/
	/* member variable                                                                     */
	/************************************************************************/
	ISceneManager* sceneManager;
	IAssetManager* assetManager;
	IInputManager* inputManager;
	IRenderManager* renderManager;
	IScriptManager* scriptManager;
	/************************************************************************/
	/* STATUS FLAG                                                                     */
	/************************************************************************/
	bool _gameStateLoopRunning;
	bool _gamePlayingLoopRunning;
	//////////////////////////////////////////////////////////////////////////
	virtual void __declspec(DLL_OUTPUT) Initialize();
	/************************************************************************/
	/* state control                                                                     */
	/************************************************************************/
	int currentState;
	/************************************************************************/
	/* initialize main menu                                                                     */
	/************************************************************************/
	GameMenuClass* gameMainMenu;
	/************************************************************************/
	/* game logic                                                                     */
	/************************************************************************/
	virtual void __declspec(DLL_OUTPUT) RunGameLogic();

};


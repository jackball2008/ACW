#pragma once
#include "IGameClass.h"
#include "ISceneManager.h"
#include "IAssetManager.h"
#include "IInputManager.h"
#include "IRenderManager.h"
#include "IScriptManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif



enum GameRunningState{CHOOSEMENU,PLAYING,UPDATELEAVEL,END,SHOWSCORE};

class GameClass : public IGameClass
{
public:
	__declspec(DLL_OUTPUT) GameClass(void);
	__declspec(DLL_OUTPUT) ~GameClass(void);
	/************************************************************************/
	/* member variable                                                                     */
	/************************************************************************/
	ISceneManager* sceneManager;
	IAssetManager* assetManager;
	IInputManager* inputManager;
	IRenderManager* renderManager;
	IScriptManager* scriptManager;


	void __declspec(DLL_OUTPUT) GameStateMainLoop();

	void __declspec(DLL_OUTPUT) GamePlayingMainLoop();

	bool __declspec(DLL_OUTPUT) ChooseStartMenu();

private:
	bool _gameStateLoopRunning;
	bool _gamePlayingLoopRunning;
};


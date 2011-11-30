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

namespace mxygameengine{

/************************************************************************/
/* declare class                                                                     */
/************************************************************************/
class GameClass;
/************************************************************************/
/* Game State                                                                     */
/************************************************************************/
enum GameRunningState{CHOOSEMENU,PLAYING,UPDATELEAVEL,END,SHOWSCORE};
/************************************************************************/
/* Game Start Menu                                                                     */
/************************************************************************/
enum GAME_MAIN_MENU{START,LOAD,SCORE,EXIT};
/************************************************************************/
/* Define MAIN MENU Callback Function Pointer                                                                     */
/************************************************************************/
typedef void(GameClass::*InterMenuCallbackP)();
typedef void(*OuterMenuCallbackP)();
/************************************************************************/
/*                                                                      */
/************************************************************************/




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
	/************************************************************************/
	/* STATUS FLAG                                                                     */
	/************************************************************************/
	bool _gameStateLoopRunning;
	bool _gamePlayingLoopRunning;
	/************************************************************************/
	/* MAIN Menu                                                                     */
	/************************************************************************/
 	InterMenuCallbackP interMainMenuP[4];
	/*OuterMenuCallbackP outerMainMenuP;*/
	void (*pf)();

	void __declspec(DLL_OUTPUT) GameStateMainLoop();

	void __declspec(DLL_OUTPUT) Initialize();

	void __declspec(DLL_OUTPUT) InitializeMainMenu();

	void __declspec(DLL_OUTPUT) ChooseMainMenuStartItemCallback();

	void __declspec(DLL_OUTPUT) ChooseMainMenuLoadItemCallback();

	void __declspec(DLL_OUTPUT) ChooseMainMenuScoreItemCallback();

	void __declspec(DLL_OUTPUT) ChooseMainMenuExitItemCallback();

	int __declspec(DLL_OUTPUT) ChooseMainMenuItem();

	void __declspec(DLL_OUTPUT) GamePlayingMainLoop();

private:
	/************************************************************************/
	/* don't use private varible here to void inherenet problem                                                                     */
	/************************************************************************/
};

/************************************************************************/
/* end of namespace                                                                     */
/************************************************************************/
}


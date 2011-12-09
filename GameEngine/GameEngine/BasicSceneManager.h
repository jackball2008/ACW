#pragma once
#include "ISceneManager.h"
/*#include "GameMenuClass.h"*/
#include "GameSceneClass.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


class BasicSceneManager : public ISceneManager
{
public:
	__declspec(DLL_OUTPUT) BasicSceneManager(void);
	__declspec(DLL_OUTPUT) ~BasicSceneManager(void);

	void __declspec(DLL_OUTPUT) Initialize();

	virtual void __declspec(DLL_OUTPUT) SetAssetManager(IAssetManager*);

	virtual void __declspec(DLL_OUTPUT) SetInputManager(IInputManager*);

	virtual void __declspec(DLL_OUTPUT) SetRenderManager(IRenderManager*);

	virtual void __declspec(DLL_OUTPUT) SetScriptManager(IScriptManager*);

	IAssetManager* _assetManager;
	IInputManager* _inputManager;
	IRenderManager* _renderManager;
	IScriptManager* _scriptManager;

	bool _hasAssetManager;
	bool _hasInputManager;
	bool _hasRenderManager;
	bool _hasScriptManager;

	/************************************************************************/
	/* main loop function                                                                     */
	/************************************************************************/
	//this is the entrance for be called in playing main loop
// 	virtual void __declspec(DLL_OUTPUT) OperateCurrentGameScene(bool *con);
// 	//begin
// 	virtual void __declspec(DLL_OUTPUT) CreateCurrentSceneEnvironment();
// 	//play
// 	virtual void __declspec(DLL_OUTPUT) RunningGameInCurrentSceneEnvironment();
// 	//end operation
// 	virtual void __declspec(DLL_OUTPUT) EndCurrentSceneEnvironment();
	/************************************************************************/
	/* Game End Flag                                                                     */
	/************************************************************************/
	
	
	/************************************************************************/
	/* Game state running callback                                                                    */
	/************************************************************************/
	//CHOOSEMENU
	char key;
	virtual void __declspec(DLL_OUTPUT) RunChooseMenu(int* gs);
	//GAMEPLAYING
	virtual void __declspec(DLL_OUTPUT) RunGamePlaying(int* gs);
	//SHOWSCORE
	virtual void __declspec(DLL_OUTPUT) RunShowScore(int* gs);
	//GAMEEXIT
	virtual void __declspec(DLL_OUTPUT) RunGameExit(int* gs);


	/************************************************************************/
	/* Main Menu                                                                     */
	/************************************************************************/
// 	GameMenuClass* mainMenu;
// 	virtual void __declspec(DLL_OUTPUT) SetMainMenu(GameMenuClass*);
	IGameSceneClass* playScene;
	virtual void __declspec(DLL_OUTPUT) SetPlayScene(IGameSceneClass*);

	virtual void __declspec(DLL_OUTPUT) PlayScene(IGameSceneClass*,int* gs);

};


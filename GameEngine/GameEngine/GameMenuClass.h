#pragma once
#include "gamesceneclass.h"
#include "FontGameSprite.h"



#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

enum GAME_MAIN_MENU{MENU_START,MENU_LOAD,MENU_SCORE,MENU_EXIT};


class GameMenuClass :
	public GameSceneClass
{
public:
	__declspec(DLL_OUTPUT) GameMenuClass(void);
	__declspec(DLL_OUTPUT) ~GameMenuClass(void);

	/************************************************************************/
	/* set menu link                                                                     */
	/************************************************************************/
	IGameSceneClass* startScene;
	IGameSceneClass* loadScene;
	IGameSceneClass* scoreScene;
	IGameSceneClass* exitScene;

	bool hasStartScene;
	bool hasLoadScene;
	bool hasScoreScene;
	bool hasExitScene;

	virtual void __declspec(DLL_OUTPUT) SetStartScene(IGameSceneClass* );
	virtual void __declspec(DLL_OUTPUT) SetLoadScene(IGameSceneClass* );
	virtual void __declspec(DLL_OUTPUT) SetScoreScene(IGameSceneClass* );
	virtual void __declspec(DLL_OUTPUT) SetExitScene(IGameSceneClass* );
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* choose                                                                     */
	/************************************************************************/
	virtual void __declspec(DLL_OUTPUT) ChooseStartItem();
	virtual void __declspec(DLL_OUTPUT) ChooseLoadItem();
	virtual void __declspec(DLL_OUTPUT) ChooseScoreItem();
	virtual void __declspec(DLL_OUTPUT) ChooseExitItem();

	/************************************************************************/
	/* override                                                                     */
	/************************************************************************/
	virtual void __declspec(DLL_OUTPUT) Begin();
	virtual void __declspec(DLL_OUTPUT) Running();
	virtual void __declspec(DLL_OUTPUT) End();
	//////////////////////////////////////////////////////////////////////////
	//menu item list
	int itemNum;
	FontGameSprite *itemList[4];
	//draw
	virtual void __declspec(DLL_OUTPUT) Draw();
};


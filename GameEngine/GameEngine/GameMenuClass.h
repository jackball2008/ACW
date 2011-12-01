#pragma once
#include "gamesceneclass.h"




#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

enum GAME_MAIN_MENU{START,LOAD,SCORE,EXIT};
typedef void(*MenuCallbackP)();

class GameMenuClass :
	public GameSceneClass
{
public:
	__declspec(DLL_OUTPUT) GameMenuClass(void);
	__declspec(DLL_OUTPUT) ~GameMenuClass(void);

	//MenuCallbackP mainMenuP[4];



};


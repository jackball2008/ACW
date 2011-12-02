#pragma once
#include "IVideoGameClass.h"
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

/************************************************************************/
/* Game State                                                                     */
/************************************************************************/
enum GameRunningState{CHOOSEMENU,PLAYING,UPDATELEAVEL,END,SHOWSCORE};
/************************************************************************/
/* Game Start Menu                                                                     */
/************************************************************************/
enum GAME_MAIN_MENU{START,LOAD,SCORE,EXIT};

class VideoGameClass : public IVideoGameClass
{
public:
	__declspec(DLL_OUTPUT) VideoGameClass(void);
	__declspec(DLL_OUTPUT) ~VideoGameClass(void);
};


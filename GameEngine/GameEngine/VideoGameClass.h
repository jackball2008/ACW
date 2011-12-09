#pragma once
#include <windows.h>
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


class VideoGameClass : public IVideoGameClass
{
public:
	__declspec(DLL_OUTPUT) VideoGameClass(void):currentSceneID(0){}
	virtual __declspec(DLL_OUTPUT) ~VideoGameClass(void){}

	/************************************************************************/
	/* member variable                                                                     */
	/************************************************************************/
	ISceneManager* sceneManager;
	IAssetManager* assetManager;
	IInputManager* inputManager;
	IRenderManager* renderManager;
	IScriptManager* scriptManager;

	
	/************************************************************************/
	/* state control                                                                     */
	/************************************************************************/
	int currentSceneID;
	

};


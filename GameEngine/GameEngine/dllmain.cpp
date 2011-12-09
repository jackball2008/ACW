#include <windows.h>
#include "MXYGameEngineInterfaceDefine.h"

//sprite
#include "mxyVector.h"
#include "GameSprite.h"
#include "FontGameSprite.h"
#include "SkeletonPoint.h"
#include "SkeletonGameSprite.h"
//scene
#include "IGameSceneClass.h"
#include "GameSceneClass.h"

//manager
#include "IManager.h"
//error manager
#include "ErrorManager.h"
//scene manager
#include "ISceneManager.h"
#include "BasicSceneManager.h"
//asset manager
#include "IAssetManager.h"
#include "BasicAssetManager.h"
//input manager
#include "IInputManager.h"
#include "BasicInputManager.h"
#include "KinectInputManager.h"
//script manager
#include "IScriptManager.h"
#include "BasicScriptManager.h"
//render manager
#include "IRenderManager.h"
#include "BasicRenderManager.h"

//game
#include "IVideoGameClass.h"
#include "VideoGameClass.h"




BOOL APIENTRY DllMain( HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// For optimization.
		DisableThreadLibraryCalls( hModule );
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
#include <windows.h>
#include "MXYGameEngineInterfaceDefine.h"

//scene
#include "IGameSceneClass.h"
#include "GameSceneClass.h"


//sprite
#include "mxyVector.h"
#include "GameSprite.h"
#include "SkeletonPoint.h"
#include "SkeletonGameSprite.h"

//manager
#include "IManager.h"
#include "ErrorManager.h"
#include "ISceneManager.h"
#include "BasicSceneManager.h"
#include "IAssetManager.h"
#include "BasicAssetManager.h"
#include "IInputManager.h"
#include "BasicInputManager.h"
#include "IRenderManager.h"
#include "BasicRenderManager.h"
#include "IScriptManager.h"
#include "BasicScriptManager.h"

#include "KinectInputManager.h"
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
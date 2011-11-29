#include <windows.h>
#include "SayHello.h"
#include "IManager.h"
#include "ISceneManager.h"
#include "BasicSceneManager.h"
#include "IAssetManager.h"
#include "BasicAssetManager.h"
#include "IInputManager.h"
#include "BasicInputManager.h"
#include "ErrorManager.h"


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
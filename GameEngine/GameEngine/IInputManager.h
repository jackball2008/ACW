#pragma once
#include "IManager.h"
#include "SkeletonGameSprite.h"


#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IInputManager : public IManager {
public:
	virtual void __declspec(DLL_OUTPUT) Initialize() = 0;

	virtual void __declspec(DLL_OUTPUT) KeyboardInput(WPARAM& wParam) = 0;
	//LPARAM 
	virtual void __declspec(DLL_OUTPUT) MouseInput(const LPARAM& lp) = 0;

	
	virtual __declspec(DLL_OUTPUT) char&  GetvKeyValue() = 0;
	virtual void __declspec(DLL_OUTPUT) RecovervKey() = 0;
	virtual __declspec(DLL_OUTPUT) UINT  GetKeyValue() = 0;


	virtual void __declspec(DLL_OUTPUT) ReleaseHardware() = 0;

	virtual void __declspec(DLL_OUTPUT) SetSkeletonDataOuptTarget(SkeletonGameSprite *) = 0;

	
	
};
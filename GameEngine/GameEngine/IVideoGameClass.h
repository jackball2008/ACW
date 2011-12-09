#pragma once
#include "MXYGameEngineInterfaceDefine.h"


#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IVideoGameClass {
public:
	virtual void __declspec(DLL_OUTPUT) Initialize(HWND hwnd,int w,int hei,int type) = 0;
	virtual void __declspec(DLL_OUTPUT) RunGameLogic() = 0;

	virtual void __declspec(DLL_OUTPUT) WM_DestoryHandler() = 0;

};
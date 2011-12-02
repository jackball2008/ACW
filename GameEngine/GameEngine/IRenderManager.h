#pragma once
#include "IManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IRenderManager : public IManager {
public:
	virtual void __declspec(DLL_OUTPUT) Initialize();

	virtual void __declspec(DLL_OUTPUT) SetRenderType(int type);

	virtual void __declspec(DLL_OUTPUT) SetWindowSize(int width, int height);



	
};
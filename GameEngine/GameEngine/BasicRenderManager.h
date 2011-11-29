#pragma once
#include "IRenderManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif
class BasicRenderManager : public IRenderManager
{
public:
	__declspec(DLL_OUTPUT) BasicRenderManager(void);
	__declspec(DLL_OUTPUT) ~BasicRenderManager(void);

	void __declspec(DLL_OUTPUT) Initialize();
};


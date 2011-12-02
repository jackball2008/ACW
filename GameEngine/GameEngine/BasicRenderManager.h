#pragma once
#include "IRenderManager.h"
#include "BasicSceneManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

enum RENDER_TYPE{OPENGL,DIECTX};

class BasicRenderManager : public IRenderManager
{
public:
	__declspec(DLL_OUTPUT) BasicRenderManager(void);
	__declspec(DLL_OUTPUT) ~BasicRenderManager(void);

	virtual void __declspec(DLL_OUTPUT) Initialize();
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	int renderType;
	void __declspec(DLL_OUTPUT) SetRenderType(int type);
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	int width,height;
	void __declspec(DLL_OUTPUT) SetWindowSize(int width, int height);
	


};


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

	void __declspec(DLL_OUTPUT) Initialize();

	void __declspec(DLL_OUTPUT) SetRenderType(int type);

	int renderType;

	

	void __declspec(DLL_OUTPUT) SetWindowSize(int width, int height);
	int width,height;

	int __declspec(DLL_OUTPUT) WINAPI InitWindow(HINSTANCE hinstance,
		HINSTANCE hprevinstance,
		LPSTR lpcmdline,
		int ncmdshow);
	LRESULT __declspec(DLL_OUTPUT) CALLBACK WindowProc(HWND hwnd, 
		UINT msg, 
		WPARAM wparam, 
		LPARAM lparam);
	
};


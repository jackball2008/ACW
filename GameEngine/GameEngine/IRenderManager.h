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

	void __declspec(DLL_OUTPUT) SetRenderType(int type);

	void __declspec(DLL_OUTPUT) SetWindowSize(int width, int height);

	int __declspec(DLL_OUTPUT) WINAPI InitWindow(HINSTANCE hinstance,
		HINSTANCE hprevinstance,
		LPSTR lpcmdline,
		int ncmdshow);
	LRESULT __declspec(DLL_OUTPUT) CALLBACK WindowProc(HWND hwnd, 
		UINT msg, 
		WPARAM wparam, 
		LPARAM lparam);

};
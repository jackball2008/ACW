#pragma once
#include <windows.h>
#include <gl\gl.h>                                // Header File For The OpenGL32 Library
#include <gl\glu.h>  
/*#include <Ole2.h>*/
#include <MSR_NuiApi.h>

/*#include "MSR_NuiApi.h"*/
#include "Skeleton.h"


class SkeletonViewer
{
public:
	SkeletonViewer(HWND hWnd, HDC hDC,int width, int height);
	~SkeletonViewer(void);

	HWND _windowHandle;
	HDC _deviceHandle;
	int _width;
	int _height;
	/*HDC			_hDC;*/

	void Initialize();
	void InitializeOpenGL(HWND hwnd, int width, int height);
	void Draw();

	
	void InitializeKinect();
	
	HANDLE NextDepthFrameEvent;
	HANDLE NextSkeletonEvent;
	HANDLE StopKinectEvent;
	
	HANDLE _depthStream;
	void dispose();
	HANDLE KinectThreadHandle;
	
	static DWORD WINAPI KinectProcessThread(LPVOID pParam);
	
	void depthEventHandler();
	void skeletonEventHandler();
	

	
	

	void buildSkeleton(NUI_SKELETON_DATA*,int&);

	
	Skeleton skeleton;

};


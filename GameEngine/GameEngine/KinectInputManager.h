#pragma once
#include "basicinputmanager.h"
#include <MSR_NuiApi.h>
#include "SkeletonGameSprite.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


class KinectInputManager :
	public BasicInputManager
{
public:
	 __declspec(DLL_OUTPUT) KinectInputManager(void);
	 __declspec(DLL_OUTPUT) ~KinectInputManager(void);

	void __declspec(DLL_OUTPUT) Initialize();

	void __declspec(DLL_OUTPUT) ReleaseHardware();

	void InitializeKinect(); 
	HANDLE NextDepthFrameEvent;
	HANDLE NextSkeletonEvent;
	HANDLE StopKinectEvent;

	HANDLE _depthStream;
	HANDLE KinectThreadHandle;
	//
	static DWORD WINAPI KinectProcessThread(LPVOID pParam);
	//
	void DepthEventHandler();
	void SkeletonEventHandler();
	void BuildSkeleton(NUI_SKELETON_DATA*,int&);
	//
	SkeletonGameSprite *skeletonSprite;
	//SkeletonPoint* SkeletonPoints[NUI_SKELETON_POSITION_COUNT];
	virtual void __declspec(DLL_OUTPUT) SetSkeletonDataOuptTarget(SkeletonGameSprite *);

};


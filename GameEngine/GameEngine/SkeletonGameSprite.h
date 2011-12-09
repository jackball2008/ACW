#pragma once
#include "gamesprite.h"
#include "SkeletonPoint.h"
#include <MSR_NuiApi.h>

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

class SkeletonGameSprite :
	public GameSprite
{
public:
	__declspec(DLL_OUTPUT) SkeletonGameSprite(void);
	virtual __declspec(DLL_OUTPUT) ~SkeletonGameSprite(void);

	SkeletonPoint SkeletonPoints[NUI_SKELETON_POSITION_COUNT];

	virtual void __declspec(DLL_OUTPUT) Draw();

};


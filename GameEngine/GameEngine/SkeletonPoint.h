#pragma once

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


struct SkeletonPoint {
	
	float x;
	float y;
	/*float z;*/
};
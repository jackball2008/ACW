#pragma once
#include <windows.h> 

#include <gl\gl.h>                                // Header File For The OpenGL32 Library
#include <gl\glu.h>  

#include <MSR_NuiApi.h>



struct SkeletonPoint {
	/*int index;*/
	float x;
	float y;
	/*float z;*/
};

class Skeleton
{
	

public:
	

	Skeleton(void);
	~Skeleton(void);

	//SkeletonPoint SkeletonPoints[20];
	SkeletonPoint SkeletonPoints[NUI_SKELETON_POSITION_COUNT];

	void draw();

};


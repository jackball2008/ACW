#pragma once
#include "gamesprite.h"


struct CUSTOMVERTEX
{
	float x, y, z;	// The transformed position for the vertex
	DWORD color;    // The vertex color
};

const CUSTOMVERTEX objectVertices[] =
{
	{  0.0f,  1.0f, -2.0f, 0xffff0000, },
	{ -1.0f, -1.0f, -2.0f, 0xffff0000, },
	{  1.0f, -1.0f, -2.0f, 0xffff0000, },
};


class FlagSprite :
	public DirectXGameSprite
{
public:
	FlagSprite(void);
	
	~FlagSprite(void);

	const float radius;

	void Draw();

	bool CheckInRange2D(const float& x,const float& y);
};


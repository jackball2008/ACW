#pragma once
#include <GXBase.h>

using namespace gxbase;

struct Vertex
{
	GLfloat position[3];        // x, y, z
	GLfloat texture[2];			// u, v
	GLfloat normal[3];			// nx, ny, nz
	GLfloat colour[4];			// r, b, g, a
	GLubyte padding[16];		// padded to 64 bytes for performance
};


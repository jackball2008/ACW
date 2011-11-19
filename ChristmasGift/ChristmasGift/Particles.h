#pragma once
#include "DisplayObjectModel.h"

#include <stdlib.h>

#define MAX_PARTICLES 100
class Particles :
	public DisplayObjectModel
{
public:
	bool rainbow;
	float   slowdown;          // Slow Down Particles
	float   xspeed;             // Base X Speed (To Allow Keyboard Direction Of Tail)
	float   yspeed;             // Base Y Speed (To Allow Keyboard Direction Of Tail)
	float   zoom;
	GLuint  loop;               // Misc Loop Variable
	GLuint  col;                // Current Color Selection
	GLuint  delay;              // Rainbow Effect Delay
	GLuint  texture;         // Storage For Our Particle Texture

	typedef struct{
		bool    active;                 // Active (Yes/No)
		float   life;                   // Particle Life
		float   fade;                   // Fade Speed

		float   r;                  // Red Value
		float   g;                  // Green Value
		float   b;                  // Blue Value

		float   x;                  // X Position
		float   y;                  // Y Position
		float   z;                  // Z Position
		
		float   xi;                 // X Direction
		float   yi;                 // Y Direction
		float   zi;                 // Z Direction
		
		float   xg;                 // X Gravity
		float   yg;                 // Y Gravity
		float   zg;                 // Z Gravity
	} particles;


	particles particle[MAX_PARTICLES];

	Particles(void);
	~Particles(void);

	void Initialize();

	void Update();

	void Draw();

	void setTexture(GLuint &t);
};


#pragma once
#include "DisplayObjectModel.h"

#define MAX_PARTICLES 1000
class Particles :
	public DisplayObjectModel
{
public:
	bool rainbow;
	float   slowdown;          // Slow Down Particles
	float   xspeed;             // Base X Speed (To Allow Keyboard Direction Of Tail)
	float   yspeed;             // Base Y Speed (To Allow Keyboard Direction Of Tail)
	float   zoom;



	Particles(void);
	~Particles(void);

	void Initialize();

	void Update();

	void Draw();
};


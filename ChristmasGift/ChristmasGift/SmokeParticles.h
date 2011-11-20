#pragma once
#include "BasicParticles.h"

#define MAXPOINTPARTICLES 1000
#define MAXPOINTSIZE 5
#define MINPOINTSIZE 1


class SmokeParticles :
	public BasicPaticles
{
public:
	SmokeParticles(void);
	~SmokeParticles(void);

	ParticlesStruct pool[MAXPOINTPARTICLES];
	void Initialize();
	void Update(const float& t);
	void Draw();
};


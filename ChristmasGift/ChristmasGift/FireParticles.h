#pragma once
#include "BasicParticles.h"
#include <math.h>

#define MAXFIREPOINTPARTICLES 500
#define MAXFIREPOINTSIZE 25
#define MINFIREPOINTSIZE 1


class FireParticles :
	public BasicParticles
{
public:
	FireParticles(void);
	~FireParticles(void);

	ParticlesStruct pool[MAXFIREPOINTPARTICLES];
	void Initialize();
	void Update(const float& t);
	void Draw();
};


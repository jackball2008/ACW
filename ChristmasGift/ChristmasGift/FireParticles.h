#pragma once
#include "BasicParticles.h"
#include <math.h>
#include "Light.h"


#define MAXFIREPOINTPARTICLES 500
#define MAXFIREPOINTSIZE 25
#define MINFIREPOINTSIZE 1


class FireParticles :
	public BasicParticles
{
public:
	FireParticles(void);
	~FireParticles(void);

	/*Lights light;*/

	ParticlesStruct pool[MAXFIREPOINTPARTICLES];
	void Initialize();
	void Update(const float& t);
	void Draw();
};


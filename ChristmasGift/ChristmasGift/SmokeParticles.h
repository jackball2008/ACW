#pragma once
#include "displayobjectmodel.h"
#include "ParticleStruct.h"

#define MAXPOINTPARTICLES 1000
#define MAXPOINTSIZE 8
#define MINPOINTSIZE 1


class SmokeParticles :
	public DisplayObjectModel
{
public:
	SmokeParticles(void);
	~SmokeParticles(void);

	PointParticle pool[MAXPOINTPARTICLES];

	void Initialize();
	void Update(const float& t);
	void Draw();

	bool working;
	void Start();
	void Stop();

	
};


#pragma once
#include "displayobjectmodel.h"
#include "ParticleStruct.h"
#include <math.h>
#include "Light.h"


#define MAXFIREPOINTPARTICLES 500
#define MAXFIREPOINTSIZE 25
#define MINFIREPOINTSIZE 1


class FireParticles :
	public DisplayObjectModel
{
public:
	FireParticles(void);
	~FireParticles(void);

	float intervaltime;
	//GLuint fire_texture_id;

	PointParticle pool[MAXFIREPOINTPARTICLES];

	void Initialize();
	void Update(const float& t);
	void Draw();

	bool working;
	void Start();
	void Stop();
};


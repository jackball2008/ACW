#pragma once
#include "displayobjectmodel.h"
#include "ParticleStruct.h"

#include "mxyVector.h"
typedef mxy::vec3<float> vec3f;

#define MAXSNOWPOINTPARTICLES 300
#define RANGEOFANGLE float(3.1415926/4)

class SnowParticleSys :
	public DisplayObjectModel
{
public:
	SnowParticleSys(void);
	~SnowParticleSys(void);

	void Initialize();
	void Update(const float& t);
	void Draw();

	void Start();
	void Stop();
	/*void DrawReflection();*/

	PointParticle pool[MAXSNOWPOINTPARTICLES];
	GLuint snow_texture0_id;

	float radius;
	float height;
	//campos replaced by global varible
	float intervaltime;
	bool working;
};


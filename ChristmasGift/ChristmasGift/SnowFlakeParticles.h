#pragma once
#include "BasicParticles.h"

#include "mxyVector.h"
typedef mxy::vec3<float> vec3f;

#define MAXPOINTPARTICLES 300
#define RANGEOFANGLE float(3.1415926/4)

class SnowFlakeParticles :
	public BasicPaticles
{
public:
	SnowFlakeParticles(void);
	~SnowFlakeParticles(void);

	GLuint  texture;         // Storage For Our Particle Texture
	float	hight;
	float	radius;

	float	camx,camy,camz;

	ParticlesStruct pool[MAXPOINTPARTICLES];
	void Initialize();
	void Update(const float& t);
	void Draw();

	void setTexture(GLuint &t);
	void setHeight(const float &h);
	void setRaius(const float &r);
	void setCameraPos(const float& x,const float& y,const float& z);

};


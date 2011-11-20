#pragma once
#include <stdlib.h>
#include "DisplayObjectModel.h"
#include "ParticleStruct.h"


#define MAXPARTICLES 500



enum ParticlesType{USEPOINT,USELINE,USETEXTURED_POLYGON};

/*typedef mxy::vec3<float> vec3f;*/

class BasicPaticles :
	public DisplayObjectModel
{
public:
	/************************************************************************/
	/* type                                                                      */
	/************************************************************************/
	ParticlesType type;
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	float   slowdown;          // Slow Down Particles
	/************************************************************************/
	/* turn on/off                                                                     */
	/************************************************************************/
	bool working;
	/************************************************************************/
	/* position of the partiles system                                                                     */
	/************************************************************************/
	GLfloat x;
	GLfloat y;
	GLfloat z;
	/************************************************************************/
	/* rate of emission                                                                     */
	/************************************************************************/
 	int rateOfEmission;
	/************************************************************************/
	/* pool                                                                     */
	/************************************************************************/
	ParticlesStruct pool[MAXPARTICLES];
	
	BasicPaticles(void);
	~BasicPaticles(void);

	void Initialize();
	void Update();
	void Draw();

	void Start();
	void Stop();

	void SetParticlesType(const ParticlesType& type);



};


#pragma once
#include "DisplayObjectModel.h"
#include "ParticleStruct.h"

#define MAXPARTICLES 500

enum ParticlesType{USEPOINT,USELINE,USETEXTURED_POLYGON};


class BasicPaticles :
	public DisplayObjectModel
{
public:
	/************************************************************************/
	/* type                                                                      */
	/************************************************************************/
	ParticlesType type;
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


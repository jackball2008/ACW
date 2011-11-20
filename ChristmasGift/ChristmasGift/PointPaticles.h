#pragma once
#include "BasicParticles.h"

/*#include "mxyVector.h"*/

 #define MAXPOINTPARTICLES 1000

class PointPaticles :
	public BasicPaticles
{
public:
	/************************************************************************/
	/* pool                                                                     */
	/************************************************************************/
	ParticlesStruct pool[MAXPOINTPARTICLES];

	PointPaticles(void);
	~PointPaticles(void);

	void Initialize();
	void Update();
	void Draw();



};


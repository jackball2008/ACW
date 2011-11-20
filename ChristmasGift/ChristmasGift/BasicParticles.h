#pragma once
#include <stdlib.h>
#include "DisplayObjectModel.h"
#include "ParticleStruct.h"


#define MAXPARTICLES 500






/*typedef mxy::vec3<float> vec3f;*/

class BasicPaticles :
	public DisplayObjectModel
{
public:
	/************************************************************************/
	/* type                                                                      */
	/************************************************************************/
	/*ParticlesType type;*/
	float intervaltime;
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
	void Update(const float& t);
	void Draw();

	void Start();
	void Stop();

	



};


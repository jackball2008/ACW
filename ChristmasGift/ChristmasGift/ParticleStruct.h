/*#include <stdlib.h>*/
/*#include <GXBase.h>*/



typedef struct{

	float size;
	/************************************************************************/
	/* color                                                                     */
	/************************************************************************/
	float   r;                  // Red Value
	float   g;                  // Green Value
	float   b;                  // Blue Value
	float	a;					//alpha

	GLuint textureID;
	/************************************************************************/
	/* postion                                                                     */
	/************************************************************************/
	float   x;                  // X Position
	float   y;                  // Y Position
	float   z;                  // Z Position

	/************************************************************************/
	/* charchter                                                                     */
	/************************************************************************/
	float	mass;
	bool    active;                 // Active (Yes/No)
	float   life;                   // Particle Life
	int		parentID;
	
	float   fade;                   // Fade Speed


	float   xi;                 // X Direction
	float   yi;                 // Y Direction
	float   zi;                 // Z Direction

	float   xg;                 // X Gravity
	float   yg;                 // Y Gravity
	float   zg;                 // Z Gravity


} ParticlesStruct;
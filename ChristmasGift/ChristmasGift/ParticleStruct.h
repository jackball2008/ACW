#pragma once
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
	float   fade;                   // Fade Speed

	int		parentID;
	
	
	float   xi;                 // X Direction
	float   yi;                 // Y Direction
	float   zi;                 // Z Direction

	float   xa;                 // X Gravity
	float   ya;                 // Y Gravity
	float   za;                 // Z Gravity

	float	x_speed;
	float	y_speed;
	float	z_speed;

	float	x_old_speed;
	float	y_old_speed;
	float	z_old_speed;


} ParticlesStruct;
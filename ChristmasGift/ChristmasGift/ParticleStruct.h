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

	float   xg;                 // X Gravity
	float   yg;                 // Y Gravity
	float   zg;                 // Z Gravity

	float	ini_x_speed;
	float	ini_y_speed;
	float	ini_z_speed;


} ParticlesStruct;
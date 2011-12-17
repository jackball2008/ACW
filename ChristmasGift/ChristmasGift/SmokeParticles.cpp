#include "SmokeParticles.h"

const float gravity = -9.8f;
const float life = 1.0f;


const float quadratic[] =  { 1.0f, 1.0f, 1.01f };

//#define FADEFUNC (float(rand()%100)/10000.0f+0.015)//float(rand()%100)/10000.0f+0.001f)
#define FADEFUNC (float(rand()%100)/100.0f+ 0.5)

#define AXFUNC 0.2f * randf1()
#define AZFUNC AXFUNC
#define AYFUNC (0.9f+randfPos1())

/************************************************************************/
/* static utils                                                                     */
/************************************************************************/
// Random floating [0-1]
static float randfPos1() {	return float(rand()) /float(RAND_MAX);}
// Random floating [-1 - 1]
static float randf1() {return randfPos1() * 2.0f - 1.0f;}
//  Random floating [-1 ,0 , 1]
static float rand2f1() {
	float val = randf1();
	return (val >0.0f) ? val*val : -(val*val);
}

SmokeParticles::SmokeParticles(void)
{
	working = false;
}


SmokeParticles::~SmokeParticles(void)
{
}

void SmokeParticles::Initialize(){

	for(int i  =0; i< MAXPOINTPARTICLES;i++){
		pool[i].active=true;                 // Make All The Particles Active
		pool[i].life=life;                   // Give All The Particles Full Life

		pool[i].fade=FADEFUNC;       // Random Fade Speed

		pool[i].r = 0.7;        // Select Red Rainbow Color
		pool[i].g = 0.7;        // Select Red Rainbow Color
		pool[i].b = 0.7;        // Select Red Rainbow Color
		pool[i].a = 1.0;

		//set point size
		pool[i].size = MAXPOINTSIZE;

		pool[i].x_speed = 0;
		pool[i].y_speed = 0;
		pool[i].z_speed = 0;

		pool[i].xa= AXFUNC;
		pool[i].ya= AYFUNC;
		pool[i].za= AZFUNC;


	}

	
}


void SmokeParticles::Update(const float& t){
	if(working){
	

	for(int loop  =0; loop< MAXPOINTPARTICLES;loop++){
	/************************************************************************/
	/* new update                                                                     */
	/************************************************************************/
	pool[loop].x_old_speed = pool[loop].x_speed;
	pool[loop].y_old_speed = pool[loop].y_speed;
	pool[loop].z_old_speed = pool[loop].z_speed;


	pool[loop].x_speed = pool[loop].x_old_speed + pool[loop].xa * t;
	pool[loop].y_speed = pool[loop].y_old_speed + pool[loop].ya * t;
	pool[loop].z_speed = pool[loop].z_old_speed + pool[loop].za * t;

	pool[loop].x = pool[loop].x + 0.5* (pool[loop].x_speed + pool[loop].x_old_speed) *t;
	pool[loop].y = pool[loop].y + 0.5* (pool[loop].y_speed + pool[loop].y_old_speed) *t;
	pool[loop].z = pool[loop].z + 0.5* (pool[loop].z_speed + pool[loop].z_old_speed) *t;

	//color from 1 to 0, life from 1 to 0, size from max to 0;
	pool[loop].life -= pool[loop].fade * t;
	pool[loop].size -= ((pool[loop].fade * pool[loop].size)/pool[loop].life) *t;
	if(pool[loop].size <= MINPOINTSIZE)pool[loop].size = MINPOINTSIZE;
	pool[loop].a    -= pool[loop].fade *t;

	if (pool[loop].life<0.0f){


		pool[loop].active=true;                 // Make All The Particles Active
		pool[loop].life=life;                   // Give All The Particles Full Life

		pool[loop].fade=FADEFUNC;       // Random Fade Speed

		pool[loop].r = 0.7;        // Select Red Rainbow Color
		pool[loop].g = 0.7;        // Select Red Rainbow Color
		pool[loop].b = 0.7;        // Select Red Rainbow Color
		pool[loop].a = 1.0;

		//set point size
		pool[loop].size = MAXPOINTSIZE;

		pool[loop].x_speed = 0;
		pool[loop].y_speed = 0;
		pool[loop].z_speed = 0;

		pool[loop].xa= AXFUNC;//randf1();                     // Set Horizontal Pull To Zero
		pool[loop].ya= AYFUNC;//randfPos1()*5;                    // Set Vertical Pull Downward
		pool[loop].za= AZFUNC;//randf1(); 

		pool[loop].x = 0;
		pool[loop].y = 0;
		pool[loop].z = 0;

	}
	}

	}
}

void SmokeParticles::Draw(){
	if(working){


	for(int loop  =0; loop< MAXPOINTPARTICLES;loop++){
		/************************************************************************/
		/* draw                                                                     */
		/************************************************************************/
		/*glPointParameterfv( GL_POINT_DISTANCE_ATTENUATION, quadratic );*/
		glPointSize( pool[loop].size );
		glPointParameterf( GL_POINT_SIZE_MAX, MAXPOINTSIZE );
		glPointParameterf( GL_POINT_SIZE_MIN, MINPOINTSIZE );
		glTexEnvf( GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE );

		glDisable( GL_CULL_FACE );
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable( GL_POINT_SPRITE );
		glBegin( GL_POINTS );
		{
			glColor4f(pool[loop].r,pool[loop].g,pool[loop].b,pool[loop].a);
			glVertex3f(pool[loop].x,pool[loop].y,pool[loop].z);
		}
		glEnd();
		glDisable( GL_POINT_SPRITE );

		glDisable(GL_BLEND);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

	}
	}
}


void SmokeParticles::Start(){
	working = true;
}
void SmokeParticles::Stop(){
	working = false;
}

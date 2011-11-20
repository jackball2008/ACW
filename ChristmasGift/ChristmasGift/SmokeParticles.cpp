#include "SmokeParticles.h"

const float gravity = -9.8f;
const float life = 1.0f;

const float x_inc = 0.001f;
const float y_inc = 0.5f;
const float z_inc = 0.001f;

const float x_ini_speed = 0.1;
const float y_ini_speed = 0.1;
const float z_ini_speed = 0.1;

const float quadratic[] =  { 1.0f, 1.0f, 1.01f };

SmokeParticles::SmokeParticles(void)
{
}


SmokeParticles::~SmokeParticles(void)
{
}

void SmokeParticles::Initialize(){
	for(int i  =0; i< MAXPOINTPARTICLES;i++){
		pool[i].active=true;                 // Make All The Particles Active
		pool[i].life=life;                   // Give All The Particles Full Life

		pool[i].fade=float(rand()%100)/1000.0f;       // Random Fade Speed

		pool[i].r = 0.7;        // Select Red Rainbow Color
		pool[i].g = 0.7;        // Select Red Rainbow Color
		pool[i].b = 0.7;        // Select Red Rainbow Color
		pool[i].a = 1.0;

		pool[i].xi= float((rand()%50)-25.0f)*10.0f;       // Random Speed On X Axis
		pool[i].yi= float((rand()%50)-25.0f)*10.0f;       // Random Speed On Y Axis
		pool[i].zi= float((rand()%50)-25.0f)*10.0f;       // Random Speed On Z Axis

		pool[i].xg=x_inc;                     // Set Horizontal Pull To Zero
		pool[i].yg=-gravity;                    // Set Vertical Pull Downward
		pool[i].zg=z_inc; 

		pool[i].size = MAXPOINTSIZE;
	}

}

void SmokeParticles::Update(const float& t){

	intervaltime = t;
	
}

void SmokeParticles::Draw(){
	for(int loop  =0; loop< MAXPOINTPARTICLES;loop++){
		/************************************************************************/
		/* draw                                                                     */
		/************************************************************************/
		glPointParameterfv( GL_POINT_DISTANCE_ATTENUATION, quadratic );
		glPointSize( 5 );
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

		/************************************************************************/
		/* draw end                                                                     */
		/************************************************************************/

		pool[loop].x+=pool[loop].xi/(1000);    // Move On The X Axis By X Speed
		pool[loop].y+=pool[loop].yi/(1000);    // Move On The Y Axis By Y Speed
		pool[loop].z+=pool[loop].zi/(1000);    // Move On The Z Axis By Z Speed

		pool[loop].xi+=pool[loop].xg;           // Take Pull On X Axis Into Account
		pool[loop].yi+=pool[loop].yg;           // Take Pull On Y Axis Into Account
		pool[loop].zi+=pool[loop].zg;           // Take Pull On Z Axis Into Account
		pool[loop].life-=pool[loop].fade;       // Reduce Particles Life By 'Fade'
		pool[loop].a -= 0.01;

		if (pool[loop].life<0.0f){						// If Particle Is Burned Out
			//reset life
			pool[loop].life=life;               // Give It New Life
			//reset fade
			pool[loop].fade=float(rand()%100)/1000.0f+0.003f;   // Random Fade Value

			//reset position
			pool[loop].x=0.0f;                  // Center On X Axis
			pool[loop].y=0.0f;                  // Center On Y Axis
			pool[loop].z=0.0f;                  // Center On Z Axis

			pool[loop].xi=float((rand()%60)-25.0f);  // X Axis Speed And Direction
			pool[loop].yi=float((rand()%60)-25.0f);  // Y Axis Speed And Direction
			pool[loop].zi=float((rand()%60)-25.0f);     // Z Axis Speed And Direction

			pool[loop].r=0.7;            // Select Red From Color Table
			pool[loop].g=0.7;            // Select Green From Color Table
			pool[loop].b=0.7;            // Select Blue From Color Table
			pool[loop].a = 1.0;
		}

	}

}

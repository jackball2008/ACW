#include "PointPaticles.h"

static GLfloat colors[12][3]=               // Rainbow Of Colors
{
	{1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
	{0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
	{0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
};
PointPaticles::PointPaticles(void)
{
	slowdown = 10.0f;	
}


PointPaticles::~PointPaticles(void)
{
}

void PointPaticles::Initialize(){
	
	for(int i  =0; i< MAXPOINTPARTICLES;i++){
		pool[i].active=true;                 // Make All The Particles Active
		pool[i].life=1.0f;                   // Give All The Particles Full Life

		pool[i].fade=float(rand()%100)/1000.0f+0.003f;       // Random Fade Speed

		pool[i].r=colors[i*(12/MAXPOINTPARTICLES)][0];        // Select Red Rainbow Color
		pool[i].g=colors[i*(12/MAXPOINTPARTICLES)][1];        // Select Red Rainbow Color
		pool[i].b=colors[i*(12/MAXPOINTPARTICLES)][2];        // Select Red Rainbow Color

		pool[i].xi=float((rand()%50)-26.0f)*10.0f;       // Random Speed On X Axis
		pool[i].yi=float((rand()%50)-25.0f)*10.0f;       // Random Speed On Y Axis
		pool[i].zi=float((rand()%50)-25.0f)*10.0f;       // Random Speed On Z Axis

		pool[i].xg=0.0f;                     // Set Horizontal Pull To Zero
		pool[i].yg=-0.8f;                    // Set Vertical Pull Downward
		pool[i].zg=0.0f; 
	}
}
void PointPaticles::Update(){
	if(working)
		for(int loop  =0; loop< MAXPOINTPARTICLES;loop++){

		}
}
void PointPaticles::Draw(){
	if(working)
		for(int loop  =0; loop< MAXPOINTPARTICLES;loop++){
			if (pool[loop].active){
				float x=pool[loop].x;               // Grab Our Particle X Position
				float y=pool[loop].y;               // Grab Our Particle Y Position
				float z=pool[loop].z;              // Particle Z Pos + Zoom

				/************************************************************************/
				/* draw                                                                     */
				/************************************************************************/
				float quadratic[] =  { 1.0f, 0.0f, 0.01f };
				glPointParameterfv( GL_POINT_DISTANCE_ATTENUATION, quadratic );
				float maxSize = 0.0f;
				glGetFloatv( GL_POINT_SIZE_MAX, &maxSize  );
				glPointSize( /*maxSize*/10 );
				glPointParameterf( GL_POINT_SIZE_MAX, maxSize );
				glPointParameterf( GL_POINT_SIZE_MIN, 0.5f );
				glTexEnvf( GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE );

				glEnable( GL_POINT_SPRITE );
				glBegin( GL_POINTS );
				{
					glColor4f(pool[loop].r,pool[loop].g,pool[loop].b,1.0f);
					glVertex3f(x,y,z);
				}
				glEnd();
				glDisable( GL_POINT_SPRITE );



				/************************************************************************/
				/* draw end                                                                     */
				/************************************************************************/
				
				pool[loop].x+=pool[loop].xi/(slowdown*1000);    // Move On The X Axis By X Speed
				pool[loop].y+=pool[loop].yi/(slowdown*1000);    // Move On The Y Axis By Y Speed
				pool[loop].z+=pool[loop].zi/(slowdown*1000);    // Move On The Z Axis By Z Speed

				pool[loop].xi+=pool[loop].xg;           // Take Pull On X Axis Into Account
				pool[loop].yi+=pool[loop].yg;           // Take Pull On Y Axis Into Account
				pool[loop].zi+=pool[loop].zg;           // Take Pull On Z Axis Into Account
				pool[loop].life-=pool[loop].fade;       // Reduce Particles Life By 'Fade'

				if (pool[loop].life<0.0f){						// If Particle Is Burned Out
					pool[loop].life=1.0f;               // Give It New Life
					pool[loop].fade=float(rand()%100)/1000.0f+0.003f;   // Random Fade Value

					pool[loop].x=0.0f;                  // Center On X Axis
					pool[loop].y=0.0f;                  // Center On Y Axis
					pool[loop].z=0.0f;                  // Center On Z Axis

					pool[loop].xi=float((rand()%60)-32.0f);  // X Axis Speed And Direction
					pool[loop].yi=float((rand()%60)-30.0f);  // Y Axis Speed And Direction
					pool[loop].zi=float((rand()%60)-30.0f);     // Z Axis Speed And Direction

					pool[loop].r=colors[0][0];            // Select Red From Color Table
					pool[loop].g=colors[0][1];            // Select Green From Color Table
					pool[loop].b=colors[0][2];            // Select Blue From Color Table
				}
			}
		}
}

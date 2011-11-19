#include "Particles.h"

static GLfloat colors[12][3]=               // Rainbow Of Colors
{
	{1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
	{0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
	{0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
};
Particles::Particles(void)
{
	rainbow = true;
}


Particles::~Particles(void)
{
}

void Particles::Initialize(){
// 	glShadeModel(GL_SMOOTH);                        // Enables Smooth Shading
// 	glClearColor(0.0f,0.0f,0.0f,0.0f);                  // Black Background
// 	glClearDepth(1.0f);                         // Depth Buffer Setup
// 	glDisable(GL_DEPTH_TEST);                       // Disables Depth Testing
	
	

	for (loop=0;loop<MAX_PARTICLES;loop++){
		particle[loop].active=true;                 // Make All The Particles Active
		particle[loop].life=1.0f;                   // Give All The Particles Full Life

		particle[loop].fade=float(rand()%100)/1000.0f+0.003f;       // Random Fade Speed
		
		particle[loop].r=colors[loop*(12/MAX_PARTICLES)][0];        // Select Red Rainbow Color
		particle[loop].g=colors[loop*(12/MAX_PARTICLES)][1];        // Select Red Rainbow Color
		particle[loop].b=colors[loop*(12/MAX_PARTICLES)][2];        // Select Red Rainbow Color
		
		particle[loop].xi=float((rand()%50)-26.0f)*10.0f;       // Random Speed On X Axis
		particle[loop].yi=float((rand()%50)-25.0f)*10.0f;       // Random Speed On Y Axis
		particle[loop].zi=float((rand()%50)-25.0f)*10.0f;       // Random Speed On Z Axis
		
		particle[loop].xg=0.0f;                     // Set Horizontal Pull To Zero
		particle[loop].yg=-0.8f;                    // Set Vertical Pull Downward
		particle[loop].zg=0.0f; 

	}

	slowdown=1.0f;
}

void Particles::Update(){}

void Particles::Draw(){
	for (loop=0;loop<MAX_PARTICLES;loop++){
		if (particle[loop].active){
			float x=particle[loop].x;               // Grab Our Particle X Position
			float y=particle[loop].y;               // Grab Our Particle Y Position
			float z=particle[loop].z+zoom;              // Particle Z Pos + Zoom

			glClearColor(0.0f,0.0f,0.0f,0.0f);
			glEnable(GL_BLEND);                         // Enable Blending
			glBlendFunc(GL_SRC_ALPHA,GL_ONE);                   // Type Of Blending To Perform
			glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);           // Really Nice Perspective Calculations
			glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);                 // Really Nice Point Smoothing


			glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
			glBindTexture(GL_TEXTURE_2D,texture); 
			// Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
			glColor4f(particle[loop].r,particle[loop].g,particle[loop].b,particle[loop].life);//

// 			glEnable(GL_POINT_SPRITE);
// 			glBegin(GL_POINT);
// 			glEnd(); 
// 			glBegin(GL_TRIANGLE_STRIP);             // Build Quad From A Triangle Strip
// 				glTexCoord2d(1,1); glVertex3f(x+0.5f,y+0.5f,z); // Top Right
// 				glTexCoord2d(0,1); glVertex3f(x-0.5f,y+0.5f,z); // Top Left
// 				glTexCoord2d(1,0); glVertex3f(x+0.5f,y-0.5f,z); // Bottom Right
// 				glTexCoord2d(0,0); glVertex3f(x-0.5f,y-0.5f,z); // Bottom Left
// 			glEnd(); 
			glDisable(GL_BLEND); 
			particle[loop].x+=particle[loop].xi/(slowdown*1000);    // Move On The X Axis By X Speed
			particle[loop].y+=particle[loop].yi/(slowdown*1000);    // Move On The Y Axis By Y Speed
			particle[loop].z+=particle[loop].zi/(slowdown*1000);    // Move On The Z Axis By Z Speed

			particle[loop].xi+=particle[loop].xg;           // Take Pull On X Axis Into Account
			particle[loop].yi+=particle[loop].yg;           // Take Pull On Y Axis Into Account
			particle[loop].zi+=particle[loop].zg;           // Take Pull On Z Axis Into Account
			particle[loop].life-=particle[loop].fade;       // Reduce Particles Life By 'Fade'

			if (particle[loop].life<0.0f){						// If Particle Is Burned Out
				particle[loop].life=1.0f;               // Give It New Life
				particle[loop].fade=float(rand()%100)/1000.0f+0.003f;   // Random Fade Value

				particle[loop].x=0.0f;                  // Center On X Axis
				particle[loop].y=0.0f;                  // Center On Y Axis
				particle[loop].z=0.0f;                  // Center On Z Axis

				particle[loop].xi=xspeed+float((rand()%60)-32.0f);  // X Axis Speed And Direction
				particle[loop].yi=yspeed+float((rand()%60)-30.0f);  // Y Axis Speed And Direction
				particle[loop].zi=float((rand()%60)-30.0f);     // Z Axis Speed And Direction

				particle[loop].r=colors[col][0];            // Select Red From Color Table
				particle[loop].g=colors[col][1];            // Select Green From Color Table
				particle[loop].b=colors[col][2];            // Select Blue From Color Table
			}                    

		}
	}
}

void Particles::setTexture(GLuint &t){
	texture = t;
}
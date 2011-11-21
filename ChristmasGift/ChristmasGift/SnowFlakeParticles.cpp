#include "SnowFlakeParticles.h"


#define FADEFUNC (float(rand()%100)/100.0f+ 0.5)
#define AXFUNC 0.2f * randf1()
#define AZFUNC AXFUNC

const float gravity = -9.8 * 0.8;
const float life = 1.0f;

const float snowflakesize = 0.1;

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
SnowFlakeParticles::SnowFlakeParticles(void)
{
}


SnowFlakeParticles::~SnowFlakeParticles(void)
{
}


void SnowFlakeParticles::Initialize(){
	for(int loop  =0; loop< MAXSNOWPOINTPARTICLES;loop++){
		float anglex = RANGEOFANGLE * randf1();
		float anflez = RANGEOFANGLE * randf1();
		pool[loop].x = radius * sin(anglex);
		float temp = radius * cos(anglex);
		pool[loop].y = temp + hight;
		pool[loop].z = radius * sin(anflez);


		pool[loop].active=true;                 // Make All The Particles Active
		pool[loop].life=life;                   // Give All The Particles Full Life

		pool[loop].r = 0.9;        // Select Red Rainbow Color
		pool[loop].g = 0.9;        // Select Red Rainbow Color
		pool[loop].b = 0.9;        // Select Red Rainbow Color
		pool[loop].a = 1.0;

		pool[loop].fade=FADEFUNC;       // Random Fade Speed


		pool[loop].x_speed = 0;
		pool[loop].y_speed = 0;
		pool[loop].z_speed = 0;

		pool[loop].xa= 0;
		pool[loop].ya= gravity;
		pool[loop].za= 0;

	}
}

void SnowFlakeParticles::Update(const float& t){
	intervaltime = t;
}
const vec3f tempup(0,1,0);
void SnowFlakeParticles::Draw(){
	
	for(int loop  =0; loop< MAXSNOWPOINTPARTICLES;loop++){

		float matrix[16];
		vec3f campos(camx,camy,camz);
		vec3f vectoreye = (campos - vec3f(pool[loop].x,pool[loop].y,pool[loop].z));
		
 		vec3f look = mxy::normalize(vectoreye);
		vec3f right = mxy::normalize(cross(look,tempup));
		vec3f rightup = mxy::normalize(cross(right,look));

		glPushMatrix();

		/*glGetFloatv(GL_MODELVIEW_MATRIX , matrix);*/

		matrix[0] = right.x;	matrix[1] =right.y;		matrix[2] = right.z;		matrix[3] = 0;

		matrix[4] = rightup.x;	matrix[5] =rightup.y;	matrix[6] = rightup.z;		matrix[7] = 0;

		matrix[8] = look.x;		matrix[9] =look.y;		matrix[10] = look.z;		matrix[11] = 0;

		/*glLoadMatrixf(matrix);*/

		glEnable(GL_BLEND);                        // Enable Blending
		glBlendFunc(GL_SRC_ALPHA,GL_ONE);                   // Type Of Blending To Perform
		glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);           // Really Nice Perspective Calculations
		glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);                // Really Nice Point Smoothing

		glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
		glBindTexture(GL_TEXTURE_2D,texture); 
		glColor4f(pool[loop].r,pool[loop].g,pool[loop].b,pool[loop].a);
		glBegin(GL_TRIANGLE_STRIP);             // Build Quad From A Triangle Strip
			glTexCoord2d(1,1); glVertex3f(pool[loop].x+snowflakesize,pool[loop].y+snowflakesize,pool[loop].z); // Top Right
			glTexCoord2d(0,1); glVertex3f(pool[loop].x-snowflakesize,pool[loop].y+snowflakesize,pool[loop].z); // Top Left
			glTexCoord2d(1,0); glVertex3f(pool[loop].x+snowflakesize,pool[loop].y-snowflakesize,pool[loop].z); // Bottom Right
			glTexCoord2d(0,0); glVertex3f(pool[loop].x-snowflakesize,pool[loop].y-snowflakesize,pool[loop].z); // Bottom Left
		glEnd(); 

		glDisable(GL_BLEND);

		glPopMatrix();

		/************************************************************************/
		/* update data                                                                     */
		/************************************************************************/
		pool[loop].x_old_speed = pool[loop].x_speed;
		pool[loop].y_old_speed = pool[loop].y_speed;
		pool[loop].z_old_speed = pool[loop].z_speed;


		pool[loop].x_speed = pool[loop].x_old_speed + pool[loop].xa * intervaltime;
		pool[loop].y_speed = pool[loop].y_old_speed + pool[loop].ya * intervaltime;
		pool[loop].z_speed = pool[loop].z_old_speed + pool[loop].za * intervaltime;

		pool[loop].x = pool[loop].x + 0.5* (pool[loop].x_speed + pool[loop].x_old_speed) *intervaltime;
		pool[loop].y = pool[loop].y + 0.5* (pool[loop].y_speed + pool[loop].y_old_speed) *intervaltime;
		pool[loop].z = pool[loop].z + 0.5* (pool[loop].z_speed + pool[loop].z_old_speed) *intervaltime;

		pool[loop].life -= pool[loop].fade * intervaltime;


		if (pool[loop].life<0.0f || pool[loop].y <0){
			pool[loop].active=true;                 // Make All The Particles Active
			pool[loop].life=life;                   // Give All The Particles Full Life
			pool[loop].fade=FADEFUNC;       // Random Fade Speed

			pool[loop].r = 0.9;        // Select Red Rainbow Color
			pool[loop].g = 0.9;        // Select Red Rainbow Color
			pool[loop].b = 0.9;        // Select Red Rainbow Color
			pool[loop].a = 1.0;

			pool[loop].x_speed = 0;
			pool[loop].y_speed = 0;
			pool[loop].z_speed = 0;

			pool[loop].xa= 0;
			pool[loop].ya= gravity;
			pool[loop].za= 0;


			float anglex = RANGEOFANGLE * randf1();
			float anflez = RANGEOFANGLE * randf1();
			pool[loop].x = radius * sin(anglex);
			float temp = radius * cos(anglex);
			pool[loop].y = temp + hight;
			pool[loop].z = radius * sin(anflez);

		}

	}

	
}

void SnowFlakeParticles::setTexture(GLuint &t){
	texture = t;
}
void SnowFlakeParticles::setHeight(const float &h){
	hight = h;
}
void SnowFlakeParticles::setRaius(const float &r){
	radius = r;
}

void SnowFlakeParticles::setCameraPos(const float& x,const float& y,const float& z){
	camx = x;
	camy = y;
	camz = z;
}
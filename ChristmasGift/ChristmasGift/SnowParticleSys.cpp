#include "SnowParticleSys.h"

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

#define FADEFUNC (float(rand()%100)/100.0f+ 0.5)
#define AXFUNC 0.2f * randf1()
#define AZFUNC AXFUNC

const float life = 1.0f;
const float gravity = -9.8 * 0.8;

SnowParticleSys::SnowParticleSys(void)
{
	working = false;
}


SnowParticleSys::~SnowParticleSys(void)
{
}

void SnowParticleSys::Initialize(){

	for(int loop  =0; loop< MAXSNOWPOINTPARTICLES;loop++){
		
		float tempr = radius * randfPos1();

		float anglex = 3.1415926 * 2 * randf1();

		pool[loop].x = tempr * cos(anglex);
		pool[loop].z = tempr * sin(anglex);

		float r = sqrt(pool[loop].x * pool[loop].x + pool[loop].z * pool[loop].z);
		float h = sqrt(radius * radius - r * r);

		pool[loop].y = h + height;

		/**
		pool[loop].x = radius * sin(anglex);
		float temp = radius * cos(anglex);
		pool[loop].y = temp + height;
		pool[loop].z = radius * sin(anflez);
		*/

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

		pool[loop].size = 10;

	}


}
void SnowParticleSys::Update(const float& t){
	if(working){
	intervaltime = t;
	for(int loop  =0; loop< MAXSNOWPOINTPARTICLES;loop++)
	{
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


// 			float anglex = RANGEOFANGLE * randf1();
// 			float anflez = RANGEOFANGLE * randf1();
// 			pool[loop].x = radius * sin(anglex);
// 			float temp = radius * cos(anglex);
// 			pool[loop].y = temp + height;
// 			pool[loop].z = radius * sin(anflez);

			float tempr = radius * randfPos1();

			float anglex = 3.1415926 * 2 * randf1();

			pool[loop].x = tempr * cos(anglex);
			pool[loop].z = tempr * sin(anglex);

			float r = sqrt(pool[loop].x * pool[loop].x + pool[loop].z * pool[loop].z);
			float h = sqrt(radius * radius - r * r);

			pool[loop].y = h + height;

		}
	}
	}
}
void SnowParticleSys::Draw(){
	if(working){
	

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, snow_texture0_id);
		glUseProgram(shaderProgramID);
		//
// 		GLint loc = glGetUniformLocation(shaderProgramID,"ColorTexture");
// 		if(loc>-1)
// 			glUniform1i(loc,0);
// 		else
// 			cout<<"uniform error"<<endl;

		//
		//////////////////////////////////////////////////////////////////////////
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();

	for(int loop  =0; loop< MAXSNOWPOINTPARTICLES;loop++){

		glPushMatrix();

		// Specify point sprite texture coordinate replacement mode for each texture unit
		glTexEnvf( GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE );

		glEnable( GL_POINT_SPRITE );
		glPointSize( pool[loop].size );

		glColor3f( pool[loop].r, pool[loop].g,pool[loop].b );

		
		glBegin( GL_POINTS );
		{
			glVertex3f( pool[loop].x,
				pool[loop].y,
				pool[loop].z );

		}
		glEnd();

		glDisable( GL_POINT_SPRITE );
		glPopMatrix();

	}
	glPopMatrix();
	glDisable(GL_BLEND);
	//////////////////////////////////////////////////////////////////////////
	glUseProgram(0);

	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE_2D);
	}
}
// void SnowParticleSys::DrawReflection(){}

void SnowParticleSys::Start(){
	working = true;
}
void SnowParticleSys::Stop(){
	working = false;
}
#include "FireParticles.h"


const float gravity = -9.8f;
const float life = 1.0f;

#define FADEFUNC (float(rand()%100)/100.0f+ 0.5)

#define AXFUNC 0.1f * randf1()
#define AZFUNC AXFUNC
#define AYFUNC (0.9f+randfPos1())

#define PXFUNC rand2f1()*0.01+randf1()*0.1
#define PYFUNC rand2f1()*0.01+randf1()*0.1 +randfPos1()*0.1
#define PZFUNC rand2f1()*0.01+randf1()*0.1

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


FireParticles::FireParticles(void)
{
	//
}


FireParticles::~FireParticles(void)
{
}


void FireParticles::Initialize(){

	for(int loop  =0; loop< MAXFIREPOINTPARTICLES;loop++){
		pool[loop].active=true;                 // Make All The Particles Active
		pool[loop].life= randfPos1();//life;                   // Give All The Particles Full Life
		pool[loop].fade= FADEFUNC;       // Random Fade Speed

		//initialize start color
		pool[loop].r = 1.0;        // Select Red Rainbow Color
		pool[loop].g = 1.0;        // Select Red Rainbow Color
		pool[loop].b = 0.8;        // Select Red Rainbow Color
		pool[loop].a = 1.0;
		//set point size
		pool[loop].size = MAXFIREPOINTSIZE;
		//speed
		pool[loop].x_speed = 0;
		pool[loop].y_speed = 0;
		pool[loop].z_speed = 0;
		//a
		pool[loop].xa= AXFUNC;
		pool[loop].ya= AYFUNC;
		pool[loop].za= AZFUNC;

		//position
		pool[loop].x = PXFUNC; //(rand()%10)*rand2f1()+randf1();
		pool[loop].y = PYFUNC; //(rand()%10)*rand2f1()+randf1();
		pool[loop].z = PZFUNC; //(rand()%10)*rand2f1()+randf1();

// 		
// 		pool[loop].matrial.create(Color::yellow(),Color::yellow(),Color(pool[loop].r,pool[loop].g,pool[loop].b,pool[loop].a));
// 		

	}
	/*light.create(5, Color::black(), Color::white());*/


}


void FireParticles::Update(const float& t){

	intervaltime = t;

}

void FireParticles::Draw(){
// 	light.apply();
// 	light.setPosition(Vector4f(0,0,0,1.0));
	for(int loop  =0; loop< MAXFIREPOINTPARTICLES;loop++){
		/************************************************************************/
		/* draw                                                                     */
		/************************************************************************/
		/*glPointParameterfv( GL_POINT_DISTANCE_ATTENUATION, quadratic );*/
		glPointSize( pool[loop].size );
		glPointParameterf( GL_POINT_SIZE_MAX, MAXFIREPOINTSIZE );
		glPointParameterf( GL_POINT_SIZE_MIN, MINFIREPOINTSIZE );
		glTexEnvf( GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE );

		glDisable( GL_CULL_FACE );
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable( GL_POINT_SPRITE );
		/*glDisable(GL_LIGHTING);*/

		//////////////////////////////////////////////////////////////////////////
		/*pool[loop].matrial.apply();*/
		
		//////////////////////////////////////////////////////////////////////////

		glBegin( GL_POINTS );
		{
			glColor4f(pool[loop].r,pool[loop].g,pool[loop].b,pool[loop].a);
			glVertex3f(pool[loop].x,pool[loop].y,pool[loop].z);
		}
		glEnd();

		/*glEnable(GL_LIGHTING);*/
		glDisable( GL_POINT_SPRITE );

		glDisable(GL_BLEND);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);


		/************************************************************************/
		/* new update                                                                     */
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

		//color from 1 to 0, life from 1 to 0, size from max to 0;
		pool[loop].life -= pool[loop].fade * intervaltime;
		pool[loop].size -= ((pool[loop].fade * pool[loop].size)/pool[loop].life) *intervaltime;
		if(pool[loop].size <= MINFIREPOINTSIZE)pool[loop].size = MINFIREPOINTSIZE;
		pool[loop].a    -= pool[loop].fade *intervaltime;

		/************************************************************************/
		/* color calculate                                                                     */
		/************************************************************************/
		pool[loop].distance = sqrt(pool[loop].x * pool[loop].x + pool[loop].y*pool[loop].y+ pool[loop].z*pool[loop].z);
		if(   pool[loop].distance >= 0.15){
			pool[loop].r = 1.0;        // Select Red Rainbow Color
			pool[loop].g = 0.97;        // Select Red Rainbow Color
			pool[loop].b = 0.5;        // Select Red Rainbow Color
			pool[loop].a = 1.0;
		}
		if(   pool[loop].distance >= 0.20){
			pool[loop].r = 0.98;        // Select Red Rainbow Color
			pool[loop].g = 0.5;        // Select Red Rainbow Color
			pool[loop].b = 0.19;        // Select Red Rainbow Color
			pool[loop].a = 1.0;
		}

		if(   pool[loop].distance >= 0.25){
			pool[loop].r = 0.55;        // Select Red Rainbow Color
			pool[loop].g = 0.22;        // Select Red Rainbow Color
			pool[loop].b = 0.08;        // Select Red Rainbow Color
			pool[loop].a = 1.0;
		}

		if(   pool[loop].distance >= 0.4){
			pool[loop].r = 0.3;        // Select Red Rainbow Color
			pool[loop].g = 0.3;        // Select Red Rainbow Color
			pool[loop].b = 0.3;        // Select Red Rainbow Color
			pool[loop].a = 0.5;
		}


		if (pool[loop].life<0.0f){

			pool[loop].active=true;                 // Make All The Particles Active
			pool[loop].life=randfPos1();                   // Give All The Particles Full Life

			pool[loop].fade=FADEFUNC;       // Random Fade Speed

			pool[loop].r = 1.0;        // Select Red Rainbow Color
			pool[loop].g = 1.0;        // Select Red Rainbow Color
			pool[loop].b = 0.8;        // Select Red Rainbow Color
			pool[loop].a = 1.0;

			//set point size
			pool[loop].size = MAXFIREPOINTSIZE;

			pool[loop].x_speed = 0;
			pool[loop].y_speed = 0;
			pool[loop].z_speed = 0;

			pool[loop].xa= AXFUNC;//randf1();                     // Set Horizontal Pull To Zero
			pool[loop].ya= AYFUNC;//randfPos1()*5;                    // Set Vertical Pull Downward
			pool[loop].za= AZFUNC;//randf1(); 

			pool[loop].x = PXFUNC;//(rand()%10)*rand2f1()+randf1();
			pool[loop].y = PYFUNC;//(rand()%10)*rand2f1()+randf1();
			pool[loop].z = PZFUNC;//(rand()%10)*rand2f1()+randf1();

		}


	}

}
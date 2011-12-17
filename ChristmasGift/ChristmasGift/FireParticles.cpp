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
	working = false;
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
		pool[loop].g = 0.5;        // Select Red Rainbow Color
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
	if(working){
	//intervaltime = t;
	for(int loop  =0; loop< MAXFIREPOINTPARTICLES;loop++){

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
		if(pool[loop].size <= MINFIREPOINTSIZE)pool[loop].size = MINFIREPOINTSIZE;
		pool[loop].a    -= pool[loop].fade *t;

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
			pool[loop].g = 0.5;        // Select Red Rainbow Color
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

// 		glUseProgram(shaderProgramID);
// 		int loc = glGetUniformLocation(shaderProgramID,"scale");
// 		if(loc!=-1)
// 			glUniform1f(loc,pool[loop].y);//same like seat
// 		else
// 			cout<<"uniform error"<<endl;
// 		glUseProgram(0);



	}


	}
}

void FireParticles::Draw(){
// 	light.apply();
// 	light.setPosition(Vector4f(0,0,0,1.0));
	if(working){
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glUseProgram(shaderProgramID);

		glEnable(GL_BLEND);//
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//
		glPushMatrix();//



	for(int loop  =0; loop< MAXFIREPOINTPARTICLES;loop++){

		int loc = glGetUniformLocation(shaderProgramID,"scale");
		if(loc!=-1)
			glUniform1f(loc,pool[loop].y);//same like seat
		else
			cout<<"uniform error"<<endl;

		glPushMatrix();//
		/************************************************************************/
		/* draw                                                                     */
		/************************************************************************/
		/*glPointParameterfv( GL_POINT_DISTANCE_ATTENUATION, quadratic );*/
		//glPointSize( pool[loop].size );
		glTexEnvf( GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE );//

// 		glPointParameterf( GL_POINT_SIZE_MAX, MAXFIREPOINTSIZE );
// 		glPointParameterf( GL_POINT_SIZE_MIN, MINFIREPOINTSIZE );
// 		glTexEnvf( GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE );
// 
// 		glDisable( GL_CULL_FACE );
// 		glEnable(GL_BLEND);
// 		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable( GL_POINT_SPRITE );
		glPointSize( pool[loop].size );//
		glColor4f(pool[loop].r,pool[loop].g,pool[loop].b,pool[loop].a);
		
		glBegin( GL_POINTS );
		{
			//glColor4f(pool[loop].r,pool[loop].g,pool[loop].b,pool[loop].a);
			glVertex3f(pool[loop].x,pool[loop].y,pool[loop].z);
		}
		glEnd();

		
		glDisable( GL_POINT_SPRITE );

		glDisable(GL_BLEND);
// 		glEnable(GL_CULL_FACE);
// 		glEnable(GL_DEPTH_TEST);
		glPopMatrix();

	}
	glPopMatrix();

	glDisable(GL_BLEND);

	glUseProgram(0);

	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE_2D);
	
	}
}


void FireParticles::Start(){
	working = true;
}
void FireParticles::Stop(){
	working = false;
}
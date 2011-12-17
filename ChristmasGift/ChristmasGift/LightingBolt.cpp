#include "LightingBolt.h"


LightingBolt::LightingBolt(void)
{
	working = false;
}


LightingBolt::~LightingBolt(void)
{
}


void LightingBolt::Update(const float& t){

}



void LightingBolt::Draw(){
	if(working){


	float matrix[16];
	glPushMatrix();
	glGetFloatv(GL_MODELVIEW_MATRIX , matrix);
	matrix[0] = matrix[10] = matrix[15] = 1.0f;
	matrix[1] = matrix[2] = matrix[8] = matrix[9] = 0.0f;
	glLoadMatrixf(matrix);

	glUseProgram(shaderProgramID);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glEnable(GL_TEXTURE_2D); 

	glDisable(GL_CULL_FACE);
	glBegin(GL_TRIANGLES);


	glNormal3f(0.0,0.0,1.0f);
// 	glVertex3f(-1.0,1.0,0.0f);
// 	glVertex3f(1.0,1.0,0.0f);
// 	glVertex3f(0.0,2.0,0.0f);
	glTexCoord2f(0,0);
	glVertex3f(-0.25f,0.0f,0.0f);
	glTexCoord2f(1,0);
	glVertex3f(0.25f,0.0f,0.0f);
	glTexCoord2f(0,1);
	glVertex3f(-0.25f,1.0f,0.0f);
	glTexCoord2f(1,0);
	glVertex3f(0.25f,0.0f,0.0f);
	glTexCoord2f(1,1);
	glVertex3f(0.25f,1.0f,0.0f);
	glTexCoord2f(0,1);
	glVertex3f(-0.25f,1.0f,0.0f);

	glEnd();
	glEnable(GL_CULL_FACE);

	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE_2D);

	glUseProgram(0);
	glPopMatrix();


	}
}

void LightingBolt::Start(){
	working = true;
}
void LightingBolt::Stop(){
	working = false;
}


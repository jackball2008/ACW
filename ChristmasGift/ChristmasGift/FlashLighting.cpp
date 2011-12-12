#include "FlashLighting.h"


FlashLighting::FlashLighting(void)
{
	work = false;

	p1[0]=p1[1]=p1[2] = 0;

	p2[0] = p2[2] = 0;

	p2[1] = 2;
}


FlashLighting::~FlashLighting(void)
{
}

void FlashLighting::Start(){
	work = true;
}
void FlashLighting::Stop(){
	work = false;
}

void FlashLighting::Draw(){
	if(!work)
	{
		glPushMatrix();
		glTranslatef(pos.x,pos.y,pos.z);
		glBegin(GL_LINE_STRIP);
		glColor3f(1,0,0);
		glLineWidth(20);
		glVertex3fv(p1);
		glVertex3fv(p2);


		glEnd();
		glPopMatrix();

	}
}

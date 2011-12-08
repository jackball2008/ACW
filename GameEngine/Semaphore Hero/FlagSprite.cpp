#include "FlagSprite.h"

//const float FlagSprite::radius = 0.05;
FlagSprite::FlagSprite(void):radius(0.03)
{
	
}


FlagSprite::~FlagSprite(void)
{
}

void FlagSprite::Draw(){
	glPushMatrix();
/*	glScalef(scale3f.x,scale3f.y,scale3f.z);*/
	glBegin(GL_LINE_STRIP);
	glColor3f(color3f.x,color3f.y,color3f.z);
	glVertex3f(pos3f.x+radius, 
		pos3f.y+radius,
		-1);
	glVertex3f(pos3f.x-radius, 
		pos3f.y+radius, 
		-1);
	glVertex3f(pos3f.x-radius, 
		pos3f.y-radius, 
		-1);
	glVertex3f(pos3f.x+radius, 
		pos3f.y-radius, 
		-1);
	glVertex3f(pos3f.x+radius, 
		pos3f.y+radius, 
		-1);
	glEnd();
	
	/**
	glBegin(GL_LINE_STRIP);
	glVertex3f(1, 
		1,
		-1);
	glVertex3f(-1, 
		1, 
		-1);
	glVertex3f(-1, 
		-1, 
		-1);
	glVertex3f(1, 
		-1, 
		-1);
	glVertex3f(1, 
		1, 
		-1);
		
	glEnd();
	*/
	glPopMatrix();
}

bool FlagSprite::CheckInRange2D(const float& x,const float& y){
// 	pos3f.x+radius  pos3f.y+radius
// 		pos3f.x-radius pos3f.y+radius
// 		pos3f.x-radius pos3f.y-radius
// 		pos3f.x+radius pos3f.y-radius

		if( 
			(x < (pos3f.x+radius) && x > (pos3f.x-radius)) 
			&&
			((y<pos3f.y+radius)&&(y>pos3f.y-radius))
			)
		{
			return true;
		}else{
			return false;
		}

}
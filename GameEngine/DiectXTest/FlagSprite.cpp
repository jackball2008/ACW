#include "FlagSprite.h"

//const float FlagSprite::radius = 0.05;
FlagSprite::FlagSprite(void):radius(0.03f)
{
	
}



FlagSprite::~FlagSprite(void)
{
}

void FlagSprite::Draw(){
	/**
	glPushMatrix();

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
	
	
	glPopMatrix();
	*/
}

bool FlagSprite::CheckInRange2D(const float& x,const float& y){
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
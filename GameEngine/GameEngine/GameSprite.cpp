#include "GameSprite.h"


GameSprite::GameSprite(void)
{
	hDC= NULL;
}


GameSprite::~GameSprite(void)
{
}

void GameSprite::Draw(){

}

void GameSprite::CalculateScreenPosition(GLdouble x,GLdouble y,GLdouble z,GLdouble *rx,GLdouble* ry,GLdouble* rz){
	GLdouble   mProj[16]; 
	GLdouble   mView[16]; 
	GLint   mPort[4]; 
	//GLdouble   res.x,res.y,res.z; 
	//得到视图，投影，视口的矩阵 
	glGetDoublev(GL_PROJECTION_MATRIX,mProj); 
	glGetDoublev(GL_MODELVIEW_MATRIX,mView); 
	glGetIntegerv(GL_VIEWPORT,mPort); 
	//模拟投影，视图，模型变换 
	gluProject(x,y,z,mView,mProj,mPort,rx,ry,rz);

	//gluProject(x,y,z,mView,mProj,mPort,rx,ry,rz);

}


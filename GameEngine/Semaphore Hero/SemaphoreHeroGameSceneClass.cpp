#include "SemaphoreHeroGameSceneClass.h"


SemaphoreHeroGameSceneClass::SemaphoreHeroGameSceneClass(void)
{
}


SemaphoreHeroGameSceneClass::~SemaphoreHeroGameSceneClass(void)
{
}

void SemaphoreHeroGameSceneClass::Begin(){

}
void SemaphoreHeroGameSceneClass::Running(){

}
void SemaphoreHeroGameSceneClass::End(){

}


void SemaphoreHeroGameSceneClass::Draw(){
	glPushMatrix();
	glScalef(0.25,0.25,1);
	skeletonPlayer.Draw();
	glPopMatrix();
	
}


#include "SemaphoreHeroGameSceneClass.h"

const float skeletonmanScale = 0.25;
SemaphoreHeroGameSceneClass::SemaphoreHeroGameSceneClass(void)
{
}


SemaphoreHeroGameSceneClass::~SemaphoreHeroGameSceneClass(void)
{
}

void SemaphoreHeroGameSceneClass::Begin(){
	//skeleton man color
	skeletonPlayer.color3f.x=1;
	skeletonPlayer.color3f.y =1;
	skeletonPlayer.color3f.z = 1;


	itemNum = 4;
	leftFlag = new FlagSprite();
// 	leftFlag->scale3f.x = 0.1;
// 	leftFlag->scale3f.y = 0.1;
// 	leftFlag->scale3f.z = 1;
	leftFlag->pos3f.x = 0;
	leftFlag->pos3f.y = 0;
	leftFlag->pos3f.z = 0;

	leftFlag->color3f.x = 1;
	leftFlag->color3f.y = 0;
	leftFlag->color3f.z = 0;

	rightFlag = new FlagSprite();
// 	rightFlag->scale3f.x = 0.1;
// 	rightFlag->scale3f.y = 0.1;
// 	rightFlag->scale3f.z = 1;
}
void SemaphoreHeroGameSceneClass::Running(){
	//logic
	float x = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_LEFT].x * skeletonmanScale;
	float y = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_LEFT].y * skeletonmanScale;

	if(x <= (leftFlag->pos3f.x - leftFlag->radius)){
		leftFlag->color3f.y = 1;
	}else{
		leftFlag->color3f.y = 0;
	}








}
void SemaphoreHeroGameSceneClass::End(){

}


void SemaphoreHeroGameSceneClass::Draw(){
	//skeleton people
	glPushMatrix();
	glScalef(skeletonmanScale,skeletonmanScale,1);
	skeletonPlayer.Draw();
	glPopMatrix();
	//left flag
	glPushMatrix();
// 	glScalef(leftFlag->scale3f.x,leftFlag->scale3f.y,leftFlag->scale3f.z);
// 	glTranslatef(leftFlag->pos3f.x,leftFlag->pos3f.y,leftFlag->pos3f.z);
	leftFlag->Draw();
	glPopMatrix();
	//right flag
	
}
void SemaphoreHeroGameSceneClass::SetInputManager(IInputManager* in){
	inputManager = in;
	inputManager->SetSkeletonDataOuptTarget(&skeletonPlayer);
}


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
	//left
	leftFlag = new FlagSprite();

	leftFlag->pos3f.x = -0.2;
	leftFlag->pos3f.y = 0;
	leftFlag->pos3f.z = 0;

	leftFlag->color3f.x = 1;
	leftFlag->color3f.y = 0;
	leftFlag->color3f.z = 0;
	//right
	rightFlag = new FlagSprite();

	rightFlag->pos3f.x = 0;
	rightFlag->pos3f.y = 0.2;
	rightFlag->pos3f.z = 0;

	rightFlag->color3f.x = 0;
	rightFlag->color3f.y = 1;
	rightFlag->color3f.z = 0;
}
void SemaphoreHeroGameSceneClass::Running(){
	//logic
	float x_left = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_LEFT].x * skeletonmanScale;
	float y_left = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_LEFT].y * skeletonmanScale;

	float x_right = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_RIGHT].x * skeletonmanScale;
	float y_right = skeletonPlayer.SkeletonPoints[NUI_SKELETON_POSITION_HAND_RIGHT].y * skeletonmanScale;

// 	if(x <= (leftFlag->pos3f.x - leftFlag->radius)){
// 		leftFlag->color3f.y = 1;
// 	}else{
// 		leftFlag->color3f.y = 0;
// 	}

	if(leftFlag->CheckInRange2D(x_left,y_left)){
		leftFlag->color3f.z = 1;
	}else{
		leftFlag->color3f.z = 0;
	}

	if(rightFlag->CheckInRange2D(x_right,y_right)){
		rightFlag->color3f.z = 1;
	}else{
		rightFlag->color3f.z = 0;
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
	glPushMatrix();
	rightFlag->Draw();
	glPopMatrix();

}
void SemaphoreHeroGameSceneClass::SetInputManager(IInputManager* in){
	inputManager = in;
	inputManager->SetSkeletonDataOuptTarget(&skeletonPlayer);
}


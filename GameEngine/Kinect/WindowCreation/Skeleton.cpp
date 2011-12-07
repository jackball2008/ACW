#include "Skeleton.h"


Skeleton::Skeleton(void)
{
}


Skeleton::~Skeleton(void)
{
}

void Skeleton::draw(){
	glPushMatrix();
	glScalef(0.35,0.35,1);
	//left hand
 	glBegin(GL_LINE_STRIP);
 	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_CENTER].x, 
 		SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_CENTER].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_LEFT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_LEFT].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_ELBOW_LEFT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_ELBOW_LEFT].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_WRIST_LEFT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_WRIST_LEFT].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_HAND_LEFT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_HAND_LEFT].y, -1);
 	glEnd();
	//right hand
	glBegin(GL_LINE_STRIP);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_CENTER].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_CENTER].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_RIGHT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_RIGHT].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_ELBOW_RIGHT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_ELBOW_RIGHT].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_WRIST_RIGHT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_WRIST_RIGHT].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_HAND_RIGHT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_HAND_RIGHT].y, -1);
	glEnd();

	//body
	glBegin(GL_LINE_STRIP);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_HEAD].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_HEAD].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_CENTER].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_SHOULDER_CENTER].y, -1);
	
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_SPINE].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_SPINE].y, -1);
	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_HIP_CENTER].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_HIP_CENTER].y, -1);
	glEnd();
	//left leg
	glBegin(GL_LINE_STRIP);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_HIP_CENTER].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_HIP_CENTER].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_HIP_LEFT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_HIP_LEFT].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_KNEE_LEFT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_KNEE_LEFT].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_ANKLE_LEFT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_ANKLE_LEFT].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_FOOT_LEFT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_FOOT_LEFT].y, -1);

	glEnd();
	
	//right leg
	glBegin(GL_LINE_STRIP);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_HIP_CENTER].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_HIP_CENTER].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_HIP_RIGHT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_HIP_RIGHT].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_KNEE_RIGHT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_KNEE_RIGHT].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_ANKLE_RIGHT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_ANKLE_RIGHT].y, -1);

	glVertex3f(SkeletonPoints[NUI_SKELETON_POSITION_FOOT_RIGHT].x, 
		SkeletonPoints[NUI_SKELETON_POSITION_FOOT_RIGHT].y, -1);

	glEnd();
	//


	glPointSize(3);
	glBegin(GL_POINTS);
	for(int i=0;i<20;i++){
		glVertex3f(SkeletonPoints[i].x,SkeletonPoints[i].y,-1);
	}
	glEnd();
	glPopMatrix();

// 	 	glBegin(GL_TRIANGLES);
// 	 	glColor3d(1, 0, 0);
// 	 	glVertex3d( 0,  1, -4);
// 	 	glVertex3d(-1, -1, -4);
// 		glVertex3d( 1, -1, -4);
// 	 	glEnd();

	
// 

}
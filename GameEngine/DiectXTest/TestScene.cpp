#include "TestScene.h"


TestScene::TestScene(void)
{
}
TestScene::TestScene(const int& rt):GameSceneClass(rt){

}

TestScene::~TestScene(void)
{
}


void TestScene::Begin(){
	//only data
	skeletonPlayer = new SkeletonGameSprite(renderType);
	skeletonPlayer->color3f.x=1;
	skeletonPlayer->color3f.y =1;
	skeletonPlayer->color3f.z = 1;


	//left flag
	leftFlag = new FlagSprite(renderType);

	leftFlag->pos3f.x = -0.2f;
	leftFlag->pos3f.y = 0;
	leftFlag->pos3f.z = 0;

	leftFlag->color3f.x = 1;
	leftFlag->color3f.y = 0;
	leftFlag->color3f.z = 0;
	//right flag
	rightFlag = new FlagSprite(renderType);

	rightFlag->pos3f.x = 0;
	rightFlag->pos3f.y = 0.2f;
	rightFlag->pos3f.z = 0;

	rightFlag->color3f.x = 0;
	rightFlag->color3f.y = 1;
	rightFlag->color3f.z = 0;

}
void TestScene::Running(){

}
void TestScene::End(){

}
void TestScene::Draw(){

}

void TestScene::SetInputManager(IInputManager* in){
	inputManager = in;
	inputManager->SetSkeletonDataOuptTarget(skeletonPlayer);
}
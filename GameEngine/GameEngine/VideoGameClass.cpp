#include "VideoGameClass.h"


VideoGameClass::VideoGameClass(void)
{
	currentState = CHOOSEMENU;
}


VideoGameClass::~VideoGameClass(void)
{
}
/************************************************************************/
/* Initialize                                                                     */
/************************************************************************/
void VideoGameClass::Initialize(){
	//initialize menu
	gameMainMenu = new GameMenuClass();
	



}
/************************************************************************/
/* game logic                                                                     */
/************************************************************************/
void VideoGameClass::RunGameLogic(){
	//std::cout<<"playing"<<std::endl;
}
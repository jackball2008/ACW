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
	//initialize menu, creat a menu scene
	gameMainMenu = new GameMenuClass();
	sceneManager->SetMainMenu(gameMainMenu);

}
/************************************************************************/
/* game logic                                                                     */
/************************************************************************/
void VideoGameClass::RunGameLogic(){
	renderManager->RenderOpenGL();
	//std::cout<<"playing"<<std::endl;
	switch(currentState){
	case CHOOSEMENU:
		sceneManager->RunChooseMenu(&currentState);
		break;
	case GAMEPLAYING:
		sceneManager->RunGamePlaying(&currentState);
		break;
	case SHOWSCORE:
		sceneManager->RunShowScore(&currentState);
		break;
	case GAMEEXIT:
		sceneManager->RunGameExit(&currentState);
		break;
	}
}
#include "GameClass.h"


GameClass::GameClass(void)
{
	std::cout<<"my game instance initialize "<<std::endl;
	_gameStateLoopRunning = false;
	_gamePlayingLoopRunning = false;
}


GameClass::~GameClass(void)
{
}

/************************************************************************/
/* main loop logic                                                                     */
/************************************************************************/
void GameClass::GameStateMainLoop(){
	_gameStateLoopRunning = true;
	while(_gameStateLoopRunning){
		//choose menu







	}
}

/************************************************************************/
/* state loop function
    ChooseStartMenu   */
/************************************************************************/
bool GameClass::ChooseStartMenu(){
	/************************************************************************/
	/* logic                                                                      */
	/************************************************************************/
	if(true){
		return true;
	}else{
		return false;
	}
}
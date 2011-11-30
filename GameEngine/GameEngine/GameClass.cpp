#include "GameClass.h"

namespace mxygameengine{




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
/* Initialize                                                                     */
/************************************************************************/
void GameClass::Initialize(){

}
/************************************************************************/
/* ini main menu                                                                     */
/************************************************************************/
void GameClass::InitializeMainMenu(){
	interMainMenuP[START] = &GameClass::ChooseMainMenuStartItemCallback;
	interMainMenuP[LOAD] = &GameClass::ChooseMainMenuLoadItemCallback;
	interMainMenuP[SCORE] = &GameClass::ChooseMainMenuScoreItemCallback;
	interMainMenuP[EXIT] = &GameClass::ChooseMainMenuExitItemCallback;
}
/************************************************************************/
/* main loop logic                                                                     */
/************************************************************************/
void GameClass::GameStateMainLoop(){
	_gameStateLoopRunning = true;
	while(_gameStateLoopRunning){
		







	}
}

/************************************************************************/
/* state loop function
    ChooseStartMenu   */
/************************************************************************/
void GameClass::ChooseMainMenuStartItemCallback(){
	/************************************************************************/
	/* logic                                                                      */
	/************************************************************************/
	
}
void GameClass::ChooseMainMenuLoadItemCallback(){

}

void GameClass::ChooseMainMenuScoreItemCallback(){

}

void GameClass::ChooseMainMenuExitItemCallback(){

}


/************************************************************************/
/* end of namespace                                                                     */
/************************************************************************/
}
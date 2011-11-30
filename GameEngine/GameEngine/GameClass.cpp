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
		int choosedMainMenuItem = ChooseMainMenuItem();
		switch(choosedMainMenuItem){
		case START:
			//*interMainMenuP[START]();
			(this->*interMainMenuP[START])();
			break;;
		case LOAD:
			(this->*interMainMenuP[LOAD])();
			break;
		case SCORE:
			(this->*interMainMenuP[SCORE])();
			break;
		case EXIT:
			(this->*interMainMenuP[EXIT])();
			break;

		default:
			break;

		}

	}
}
/************************************************************************/
/* choose main menu item                                                                     */
/************************************************************************/
int GameClass::ChooseMainMenuItem(){
	int res;
	//res = START;
	std::cin>>res;
	return res;
}


/************************************************************************/
/* state loop function
    ChooseStartMenu   */
/************************************************************************/
void GameClass::ChooseMainMenuStartItemCallback(){
	/************************************************************************/
	/* logic                                                                      */
	/************************************************************************/
	GamePlayingMainLoop();
	std::cout<<"Start"<<endl;
}
void GameClass::ChooseMainMenuLoadItemCallback(){
	std::cout<<"Load"<<endl;
}

void GameClass::ChooseMainMenuScoreItemCallback(){
	std::cout<<"Score"<<endl;
}

void GameClass::ChooseMainMenuExitItemCallback(){
	std::cout<<"Exit"<<endl;
	_gameStateLoopRunning = false;
}
/************************************************************************/
/* game playing main loop                                                                     */
/************************************************************************/
void GameClass::GamePlayingMainLoop(){
	_gamePlayingLoopRunning = true;
	while(_gamePlayingLoopRunning){
		_gamePlayingLoopRunning = false;
		std::cout<<"Game Level Update"<<endl;
		std::cout<<"Game Level Play"<<endl;
		//do update and play
		sceneManager->OperateCurrentGameScene(&_gamePlayingLoopRunning);
		

	}
}


/************************************************************************/
/* end of namespace                                                                     */
/************************************************************************/
}
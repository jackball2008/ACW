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
	//interMainMenuP[START] = &GameClass::ChooseMainMenuStartItemCallback;
	//interMainMenuP[LOAD] = &GameClass::ChooseMainMenuLoadItemCallback;
	//interMainMenuP[SCORE] = &GameClass::ChooseMainMenuScoreItemCallback;
	//interMainMenuP[EXIT] = &GameClass::ChooseMainMenuExitItemCallback;
	//mainMenu
	//mainMenu = new GameMenuClass();
	//outerMainMenuP[START] = &GameClass::ChooseMainMenuStartItemCallback;
	//outerMainMenuP[LOAD] = &GameClass::ChooseMainMenuLoadItemCallback;
	//outerMainMenuP[SCORE] = &GameClass::ChooseMainMenuScoreItemCallback;
	//outerMainMenuP[EXIT] = &GameClass::ChooseMainMenuExitItemCallback;
	
}
/************************************************************************/
/* main loop logic                                                                     */
/************************************************************************/
void GameClass::GameStateMainLoop(){
	_gameStateLoopRunning = true;
	while(_gameStateLoopRunning){
		int choosedMainMenuItem = ChooseMainMenuItem();
		switch(choosedMainMenuItem){
			/**
		case MENU_START:
			//*interMainMenuP[START]();
			//(this->*interMainMenuP[START])();
			ChooseMainMenuStartItemCallback();
			//(mainMenu->*interMainMenuP[START])();
			break;;
		case MENU_LOAD:
			//(this->*interMainMenuP[LOAD])();
			ChooseMainMenuLoadItemCallback();
			//(mainMenu->*interMainMenuP[LOAD])();
			break;
		case MENU_SCORE:
			//(this->*interMainMenuP[SCORE])();
			ChooseMainMenuScoreItemCallback();
			//(mainMenu->*interMainMenuP[SCORE])();
			break;
		case MENU_EXIT:
			//(this->*interMainMenuP[EXIT])();
			ChooseMainMenuExitItemCallback();
			//(mainMenu->*interMainMenuP[EXIT])();
			break;
			*/
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
		//_gamePlayingLoopRunning = false;
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
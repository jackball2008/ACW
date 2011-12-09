#include "BasicInputManager.h"


BasicInputManager::BasicInputManager(void)
{
}


BasicInputManager::~BasicInputManager(void)
{
}



void BasicInputManager::KeyboardInput(WPARAM& wParam){
	vkey = (char)wParam;
	keyvalue = wParam;
}

char& BasicInputManager::GetvKeyValue(){
	return vkey;
}
void BasicInputManager::RecovervKey(){
	vkey = '.';
}
//LPARAM 
void BasicInputManager::MouseInput(const LPARAM& lp){

}
UINT  BasicInputManager::GetKeyValue(){
	return keyvalue;
}


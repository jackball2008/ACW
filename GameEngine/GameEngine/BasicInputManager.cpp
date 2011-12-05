#include "BasicInputManager.h"


BasicInputManager::BasicInputManager(void)
{
}


BasicInputManager::~BasicInputManager(void)
{
}

void BasicInputManager::Initialize(){
	MessageBoxA(0,"Input Manager Initialize ok ","", MB_OK);
}

void BasicInputManager::KeyboardInput(WPARAM& wParam){
	/*key = wParam;*/
	vkey = (char)wParam;
	keyvalue = wParam;
}
// WPARAM BasicInputManager::GetKeyValue(){
// 	return key;
// }
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
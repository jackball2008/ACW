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
// 	char message[15];
// 	sprintf_s(message, "Key Pressed: %c", (char)wParam);
// 	MessageBoxA(NULL, message, "Key Pressed", MB_OK);
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
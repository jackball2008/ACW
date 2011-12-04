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

void BasicInputManager::KeyboardInput(const UINT& msg){
	MessageBoxA(0,"Input Manager Initialize ok + %d"+ msg,"", MB_OK);
}
//LPARAM 
void BasicInputManager::MouseInput(const LPARAM& lp){

}
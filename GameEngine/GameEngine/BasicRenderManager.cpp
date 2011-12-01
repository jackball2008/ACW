#include "BasicRenderManager.h"


BasicRenderManager::BasicRenderManager(void)
{
	renderType = OPENGL;
	width = height = 0;
}


BasicRenderManager::~BasicRenderManager(void)
{
}

void BasicRenderManager::Initialize(){
// 	MessageBoxA(0,"Render Manager Initialize ok ","", MB_OK);
// 	HINSTANCE hInstance = (HINSTANCE)::GetModuleHandle(NULL);
	
}
void BasicRenderManager::SetRenderType(int type){
	renderType = type;
}
void BasicRenderManager::SetWindowSize(int w, int h){
	width = w;
	height = h;
}

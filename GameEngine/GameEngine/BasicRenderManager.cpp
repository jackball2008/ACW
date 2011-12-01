#include "BasicRenderManager.h"


BasicRenderManager::BasicRenderManager(void)
{
	renderType = OPENGL;
	width = height = 0;
}


BasicRenderManager::~BasicRenderManager(void)
{
}
/************************************************************************/
/*                                                                      */
/************************************************************************/

/************************************************************************/
/*                                                                      */
/************************************************************************/
void BasicRenderManager::Initialize(){
	MessageBoxA(0,"Render Manager Initialize ok ","", MB_OK);
	HINSTANCE hInstance = (HINSTANCE)::GetModuleHandle(NULL);
}
void BasicRenderManager::SetRenderType(int type){
	renderType = type;
}
void BasicRenderManager::SetWindowSize(int w, int h){
	width = w;
	height = h;
}
int WINAPI BasicRenderManager::InitWindow(HINSTANCE hinstance,
	HINSTANCE hprevinstance,
	LPSTR lpcmdline,
	int ncmdshow){
	
		/************************************************************************/
		/* start to creat window                                                                     */
		/************************************************************************/
		WNDCLASS	winclass;	// this will hold the class we create
		HWND		hwnd;		// generic window handle
		MSG			msg;		// generic message

		// first fill in the window class stucture
		winclass.style			= CS_HREDRAW | CS_VREDRAW;                  
		winclass.lpfnWndProc	= WindowProc;
		winclass.cbClsExtra		= 0;
		winclass.cbWndExtra		= 0;
		winclass.hInstance		= hinstance;
		winclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
		winclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
		winclass.hbrBackground  = (HBRUSH)GetStockObject(BLACK_BRUSH);
		winclass.lpszMenuName	= NULL;
		winclass.lpszClassName	= "WindowCreation";


		return 1;
}

LRESULT CALLBACK BasicRenderManager::WindowProc(HWND hwnd, 
	UINT msg, 
	WPARAM wparam, 
	LPARAM lparam){



		return (DefWindowProc(hwnd, msg, wparam, lparam));
}


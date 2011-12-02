#include "GameClassDefine.h"
#include "MainFunctionDefine.h"
#include "ManagerDefine.h"

#define USEOPENGL
#define USEWINDOW

const char TITLE[] = "Window CreationA";
const int width = 800;
const int height = 600;

//************************ MESSAGE HANDLER **************************

LRESULT CALLBACK WindowProc(HWND hwnd, 
	UINT msg, 
	WPARAM wparam, 
	LPARAM lparam)
{
	// this is the main message handler of the system
	PAINTSTRUCT		ps;	// used in WM_PAINT
	HDC				hdc;	// handle to a device context

	// what is the message 
	switch(msg)
	{	
	case WM_CREATE: 
		{
			// do initialization stuff here
			return(0);
		} 

	case WM_PAINT: 
		{
			// validate the window
			hdc = BeginPaint(hwnd,&ps);	 
			EndPaint(hwnd,&ps);
			return(0);
		} 

	case WM_KEYDOWN:
		{
			// Handle any non-accelerated key commands
			switch (wparam)
			{
			case VK_ESCAPE:
			case VK_F12:
				PostMessage(hwnd, WM_CLOSE, 0, 0);
				return (0);
			default:
				char message[15];
				sprintf_s(message, "Key Pressed: %c", (char)wparam);
				//MessageBoxA(NULL, message, "Key Pressed", MB_OK);
			}
			break;
		}

	case WM_DESTROY: 
		{
			// kill the application			
			PostQuitMessage(0);

			return(0);
		}

	default:
		break;

	} // end switch

	// process any messages that we didn't take care of 
	return (DefWindowProc(hwnd, msg, wparam, lparam));

} // end WinProc




int WINAPI WinMain( HINSTANCE hinstance,
	HINSTANCE hprevinstance,
	LPSTR lpcmdline,
	int ncmdshow)
{
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

	// register the window class
	if (!RegisterClass(&winclass))
		return(0);

	// create the window
	if (!(hwnd = CreateWindow( "WindowCreation", // class
		TITLE,	     // title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,
		0,
		//Set the size of the window to the size of the screen 
		width,
		height,
		NULL,	   // handle to parent 
		NULL,	   // handle to menu
		hinstance,	// instance
		NULL)))	// creation parms
		return(0);

	/************************************************************************/
	/* initialize vary member variable                                                                     */
	/************************************************************************/
	//InitializeGameClass();
	
	/************************************************************************/
	/* initialize end                                                                     */
	/************************************************************************/
	// enter main event loop
	bool quit = false;
	while(!quit)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{ 
			// test if this is a quit
			if (msg.message == WM_QUIT) quit = true;

			// translate any accelerator keys
			TranslateMessage(&msg);
			// send the message to the window proc
			DispatchMessage(&msg);
		} // end if
		else {
			/************************************************************************/
			/* do some main logic control                                                                     */
			/************************************************************************/








		}

	} // end while

	return(msg.wParam);

} 


/**
void main( int argc, const char* argv[])
{
	InitializeGameClass();
	int k;
	cin>>k;
}
*/
void InitializeGameClass(){
	myGame.assetManager = new BasicAssetManager();
	myGame.inputManager = new BasicInputManager();
	myGame.renderManager = new BasicRenderManager();
	myGame.scriptManager = new BasicScriptManager();
	//myGame.sceneManager = new BasicSceneManager();
	myGame.sceneManager = new GameSceneManager();
	//very important
	BindSceneManagerAndOtherManagers();
	/************************************************************************/
	/* initialize every manager                                                                     */
	/************************************************************************/
	/************************************************************************/
	/* rendermanager initialize                                                                     */
	/************************************************************************/
#ifdef USEOPENGL
	myGame.renderManager->SetRenderType(OPENGL);
#else
	myGame.renderManager->SetRenderType(DIECTX);
#endif
	myGame.renderManager->SetWindowSize(width,height);
	myGame.renderManager->Initialize();

	/************************************************************************/
	/* game ini and go                                                                     */
	/************************************************************************/
	myGame.Initialize();
	myGame.InitializeMainMenu();
	myGame.GameStateMainLoop();
	
}



void BindSceneManagerAndOtherManagers(){
	myGame.sceneManager->SetAssetManager(myGame.assetManager);
	myGame.sceneManager->SetInputManager(myGame.inputManager);
	myGame.sceneManager->SetRenderManager(myGame.renderManager);
	myGame.sceneManager->SetScriptManager(myGame.scriptManager);

}




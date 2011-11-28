#include <stdio.h>
#include <Windows.h>

#include "SayHello.h"

const char TITLE[] = "Window Creation";


#pragma comment(lib,"GameEngine.lib")

//********************Direct 3D Initialization********************************
#include <d3d9.h>
#include <d3dx9.h>
LPDIRECT3D9             g_pD3D       = NULL; 
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; 

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE) 

#define USEOPENGL1

// Buffer to hold vertices
LPDIRECT3DVERTEXBUFFER9	vbo        = NULL; 

struct CUSTOMVERTEX
{
    float x, y, z;	// The transformed position for the vertex
    DWORD color;    // The vertex color
};

CUSTOMVERTEX vertices[] =
{
     {  0.0f,  1.0f, -2.0f, 0xffff0000, },
     { -1.0f, -1.0f, -2.0f, 0xffff0000, },
     {  1.0f, -1.0f, -2.0f, 0xffff0000, },
};

D3DXMATRIX g_matProj;  
D3DXMATRIX g_matView;
D3DXMATRIX g_matWorld;

//*****************************************************************************

//********************OpenGL Initialization********************************
#include <gl\gl.h>                                // Header File For The OpenGL32 Library
#include <gl\glu.h>                               // Header File For The GLu32 Library
HDC			hDC=NULL;		// Private GDI Device Context
//*****************************************************************************

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
				MessageBox(NULL, message, "Key Pressed", MB_OK);
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



//**************************Setup OpenGL***********************
void InitializeOpenGL(HWND hwnd, int width, int height)
{ 
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	HGLRC		hRC=NULL;		// Permanent Rendering Context
	HWND		hWnd=NULL;		// Holds Our Window Handle

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		24,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC=GetDC(hwnd)))							// Did We Get A Device Context?
	{
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window

	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

}

//**************************Render and display the scene in OpenGL***********************
void RenderOpenGL()									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	// Rendering of scene objects can happen here
	glBegin(GL_TRIANGLES);
		glColor3d(1, 0, 0);
		glVertex3d( 0,  1, -4);
		glVertex3d(-1, -1, -4);
		glVertex3d( 1, -1, -4);
	glEnd();

	SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
}



//**************************Setup DirectX***********************
void InitializeDX(HWND hwnd, int width, int height)
{ 
	if(!( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		MessageBox(hwnd,"Direct3d Create problem", NULL, NULL);

	//D3DPRESENT_PARAMETERS d3dpp; 
	//ZeroMemory( &d3dpp, sizeof(d3dpp) );
	//d3dpp.Windowed = TRUE;
	//d3dpp.SwapEffect = D3DSWAPEFFECT_COPY;
	//d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;  
	//d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	//d3dpp.hDeviceWindow = hwnd;	
	//d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	D3DPRESENT_PARAMETERS d3dpp; 
	ZeroMemory( &d3dpp, sizeof(d3dpp) );
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_COPY;
	//d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;  
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.hDeviceWindow = hwnd;	
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.EnableAutoDepthStencil = TRUE;

	HRESULT hr = S_OK;
	hr = g_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_FPU_PRESERVE,
		&d3dpp, &g_pd3dDevice

		);

	//*************************** Create Vertex Buffer ****************************
	if( FAILED( g_pd3dDevice->CreateVertexBuffer( 3*sizeof(CUSTOMVERTEX),
												  0 /* Usage */, D3DFVF_CUSTOMVERTEX,
												  D3DPOOL_MANAGED, &vbo, NULL ) ) )
		MessageBox(hwnd,"Vertex Buffer problem",NULL,NULL);;

	VOID* pVertices;
	if( FAILED( vbo->Lock( 0, sizeof(vertices), (void**)&pVertices, 0 ) ) )
		MessageBox(hwnd,"Vertex Lock Problem",NULL,NULL);

	memcpy( pVertices, vertices, sizeof(vertices) );

	vbo->Unlock();

		// turn on the z-buffer
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	// Turn off D3D lighting, since we are
    // providing our own vertex colours
    g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
    // Turn off culling, so we see the front and back of the triangle
    g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );


	// Set up our view matrix. A view matrix can be defined given an 
	// eye point, a point to look at, and a direction for which way
	// is up. Here, we set the eye five units back along the z-axis
	// , look at the origin, and define "up" to be
	// in the y-direction.
	D3DXMatrixLookAtLH( &g_matView, &D3DXVECTOR3( 0.0f, 0.0f, 1.0f ),
				  &D3DXVECTOR3( 0.0f, 0.0f, 0.0f ),
				  &D3DXVECTOR3( 0.0f, 1.0f, 0.0f ) );
	g_pd3dDevice->SetTransform( D3DTS_VIEW, &g_matView );
	  
	// For the projection matrix, we set up a perspective transform 
	// (which transforms geometry from 3D view space to 2D viewport 
	// space, with a perspective divide making objects smaller in the 
	// distance). To build a perpsective transform, we need the width of the world window,
	// the width of the world window divided by the aspect ratio of the world window, 
	// and the near and far clipping planes (which define at what 
	// distances geometry should be no longer be rendered).
	//D3DXMatrixPerspectiveLH(&g_matProj, 2.0f, 2.0f/1.5f, 1.0f, 10000.0f);
	D3DXMatrixPerspectiveFovLH(&g_matProj,45.0f,(float)width/(float)height,0.1f,100.0f);
	g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &g_matProj );
}


//**************************Render and display the scene in DirectX***********************
void RenderDX()
{
	g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,0), 1.0f, 0 );

	// Begin the scene
	if( SUCCEEDED( g_pd3dDevice->BeginScene() ) )
	{
		// Rendering of scene objects can happen here
		g_pd3dDevice->SetStreamSource( 0, vbo, 0, sizeof(CUSTOMVERTEX) );
		g_pd3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
		g_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 1 );

		// End the scene
		g_pd3dDevice->EndScene();
	}

	g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}



//************************ WIN MAIN***********************

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
		600,
		400,
		//GetSystemMetrics(SM_CXSCREEN),
		//GetSystemMetrics(SM_CYSCREEN),
		NULL,	   // handle to parent 
		NULL,	   // handle to menu
		hinstance,	// instance
		NULL)))	// creation parms
		return(0);
#ifdef USEOPENGL
	InitializeOpenGL(hwnd, 600, 400);
#else
	InitializeDX(hwnd, 600, 400);
#endif
	//
	SayHello hello222;
	hello222.DisplayHelloMessage();

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
#ifdef USEOPENGL
			RenderOpenGL();
#else
			RenderDX();
#endif
			//
			
		}

	} // end while

	// return to Windows like this
	return(msg.wParam);

} // end WinMain


//************************ END OF WIN MAIN ***********************

#include "BasicRenderManager.h"


BasicRenderManager::BasicRenderManager(void)
{
	width = height = 0;
	hDC=NULL;
	g_pD3D       = NULL; 
	g_pd3dDevice = NULL; 
}


BasicRenderManager::~BasicRenderManager(void)
{
}

//**************************Setup OpenGL***********************
void BasicRenderManager::InitializeOpenGL(HWND hwnd,int w,int hei)
{ 
	width = w;
	height = hei;

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

	if (hei==0)										// Prevent A Divide By Zero By
	{
		hei=1;										// Making Height Equal One
	}

	glViewport(0,0,w,hei);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)w/(GLfloat)hei,0.1f,100.0f);

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
void BasicRenderManager::RenderOpenGL(IGameSceneClass* scene)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	scene->Draw();
	
	SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
}


//
void BasicRenderManager::InitializeDX(HWND hwnd, int width, int height){
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
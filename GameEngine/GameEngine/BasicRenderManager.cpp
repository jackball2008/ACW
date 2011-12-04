#include "BasicRenderManager.h"


BasicRenderManager::BasicRenderManager(void)
{
	renderType = OPENGL;
	width = height = 0;
	hDC=NULL;
}


BasicRenderManager::~BasicRenderManager(void)
{
}

void BasicRenderManager::Initialize(){
// 	MessageBoxA(0,"Render Manager Initialize ok ","", MB_OK);
}
void BasicRenderManager::SetRenderType(int type){
	renderType = type;
}
void BasicRenderManager::SetWindowSize(int w, int h){
	width = w;
	height = h;
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




	//BuildFont();
	fs.BuildFont();

}

//**************************Render and display the scene in OpenGL***********************
void BasicRenderManager::RenderOpenGL()									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix


	

	
	// Rendering of scene objects can happen here
	glTranslatef(0.0f,0.0f,-1.0f);
	//glColor3f(1.0f*float(cos(cnt1)),1.0f*float(sin(cnt2)),1.0f-0.5f*float(cos(cnt1+cnt2)));
	//glRasterPos2f(-0.45f+0.05f*float(cos(cnt1)), 0.35f*float(sin(cnt2)));
	glColor3f(1,1,1);
	glRasterPos2f(0.1f,0.0f);
	fs.glPrint("Active OpenGL Text With NeHe - %7.2f", 99.0);
	//glPrint("Active OpenGL Text With NeHe - %7.2f", cnt1);
	glColor3f(1,0,0);
	glRasterPos2f(0,0.1);
	fs.glPrint("A");
	/**
	glBegin(GL_TRIANGLES);
		glColor3d(1, 0, 0);
		glVertex3d( 0,  1, -4);
		glVertex3d(-1, -1, -4);
		glVertex3d( 1, -1, -4);
	glEnd();
	*/
	SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
}

/**
GLvoid BasicRenderManager::BuildFont(GLvoid){
	HFONT	font;
	HFONT	oldfont;
	base = glGenLists(96);
	font = CreateFont( -50,
		0,
		0,
		0,
		FW_BOLD,
		FALSE,
		FALSE,
		FALSE,
		ANSI_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY,
		FF_DONTCARE|DEFAULT_PITCH,
		"Courier New"
		);
	oldfont = (HFONT)SelectObject(wglGetCurrentDC(), font);
	//wglUseFontBitmaps(hDC, 32, 96, base);
	wglUseFontBitmaps(wglGetCurrentDC(), 32, 96, base);
	
	SelectObject(wglGetCurrentDC(), oldfont);
	DeleteObject(font);
}
GLvoid BasicRenderManager::glPrint(const char *fmt, ...){
	char		text[256];
	va_list		ap;
	if (fmt == NULL)
		return;
	va_start(ap, fmt);
	vsprintf(text, fmt, ap);
	va_end(ap);
	glPushAttrib(GL_LIST_BIT);
	glListBase(base - 32);
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);
	glPopAttrib();

}
*/
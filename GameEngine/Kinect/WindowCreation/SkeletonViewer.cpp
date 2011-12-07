#include "SkeletonViewer.h"


SkeletonViewer::SkeletonViewer(HWND hWnd, HDC hDC,int width, int height)
	:_windowHandle(hWnd),
	_deviceHandle(hDC),
	_width(width),
	_height(height)//,
	/*_hDC(hDC)*/
{
}


SkeletonViewer::~SkeletonViewer(void)
{
	dispose();
}

void SkeletonViewer::Initialize(){
	InitializeOpenGL(_windowHandle,_width,_height);
	InitializeKinect();

}
void SkeletonViewer::InitializeOpenGL(HWND hwnd, int width, int height)
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

	if (!(_deviceHandle=GetDC(hwnd)))							// Did We Get A Device Context?
	{
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	if (!(PixelFormat=ChoosePixelFormat(_deviceHandle,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	if(!SetPixelFormat(_deviceHandle,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	if (!(hRC=wglCreateContext(_deviceHandle)))				// Are We Able To Get A Rendering Context?
	{
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	if(!wglMakeCurrent(_deviceHandle,hRC))					// Try To Activate The Rendering Context
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

void SkeletonViewer::Draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	skeleton.draw();
	// Rendering of scene objects can happen here
// 	glBegin(GL_TRIANGLES);
// 	glColor3d(1, 0, 0);
// 	glVertex3d( 0,  1, -4);
// 	glVertex3d(-1, -1, -4);
// 	glVertex3d( 1, -1, -4);
// 	glEnd();

	SwapBuffers(_deviceHandle);
}



void SkeletonViewer::InitializeKinect(){
	NextDepthFrameEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	NextSkeletonEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	StopKinectEvent = CreateEvent(NULL,FALSE,FALSE,NULL);

	HRESULT hr;
	hr= NuiInitialize(
		NUI_INITIALIZE_FLAG_USES_DEPTH_AND_PLAYER_INDEX |
		NUI_INITIALIZE_FLAG_USES_SKELETON
		);
	if(FAILED(hr)){
		MessageBox(_windowHandle,"Could not initialize kinect device","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	hr = NuiSkeletonTrackingEnable(NextSkeletonEvent,0);

	hr = NuiImageStreamOpen(
		NUI_IMAGE_TYPE_DEPTH_AND_PLAYER_INDEX,
		NUI_IMAGE_RESOLUTION_320x240,
		0,
		2,
		NextDepthFrameEvent,
		&_depthStream
		);
	KinectThreadHandle = CreateThread(NULL,0,KinectProcessThread,this,0,NULL);

}
void SkeletonViewer::dispose(){
	if(StopKinectEvent != NULL){

		SetEvent(StopKinectEvent);

		if(KinectThreadHandle!=NULL){
			WaitForSingleObject(KinectThreadHandle,INFINITE);
			CloseHandle(KinectThreadHandle);
		}
		CloseHandle(StopKinectEvent);
	}

	NuiShutdown();

	if(NextSkeletonEvent && ( NextSkeletonEvent != INVALID_HANDLE_VALUE)){
		CloseHandle(NextSkeletonEvent);
		NextSkeletonEvent = NULL;
	}
	if(NextDepthFrameEvent && ( NextDepthFrameEvent != INVALID_HANDLE_VALUE ) ){
		CloseHandle(NextDepthFrameEvent);
		NextDepthFrameEvent = NULL;
	}


}


//thread
DWORD WINAPI SkeletonViewer::KinectProcessThread(LPVOID pParam){
	//get a pointer to this
	SkeletonViewer* app = (SkeletonViewer*)pParam;

	HANDLE hEvents[3];
	hEvents[0] = app->StopKinectEvent;
	hEvents[2] = app->NextDepthFrameEvent;
	hEvents[1] = app->NextSkeletonEvent;

// 	HANDLE hEvents[2];
// 	hEvents[0] = app->StopKinectEvent;
// 	hEvents[1] = app->NextSkeletonEvent;

	int eventID;

	while(true){
		
		eventID = WaitForMultipleObjects(sizeof(hEvents)/sizeof(hEvents[0]),hEvents,FALSE, 100);
		
		//stop event
		if(eventID == 0)
			break;

		//process events
		switch(eventID){
		case 2:
			app->depthEventHandler();
			break;
		case 1:
			app->skeletonEventHandler();
			break;

// 		case 1:
// 			app->skeletonEventHandler();
// 			break;

		}


	}

	return 0;


}

void SkeletonViewer::depthEventHandler(){
	
}

void SkeletonViewer::skeletonEventHandler(){
	
	NUI_SKELETON_FRAME skeletonFrame;
	
	HRESULT hr = NuiSkeletonGetNextFrame(0,&skeletonFrame);

	bool foundSkeleton = false;
	for(int i = 0;i< NUI_SKELETON_COUNT;i++){
		if(skeletonFrame.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){
			foundSkeleton = true;
		}
	}

	//quite if there are no actively tracked skeletons
	if(!foundSkeleton){
		return;
	}

	NuiTransformSmooth(&skeletonFrame,NULL);

	//go though skeletons to find the active ones
	for(int i = 0;i < NUI_SKELETON_COUNT;i++){
		if(skeletonFrame.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){
			buildSkeleton(&skeletonFrame.SkeletonData[i],i);
		}
	}
}

void SkeletonViewer::buildSkeleton(NUI_SKELETON_DATA* skeletonData,int& i){
	for(int i = 0;i<NUI_SKELETON_POSITION_COUNT;i++){
 		skeleton.SkeletonPoints[i].x = skeletonData->SkeletonPositions[i].x;
 		skeleton.SkeletonPoints[i].y = skeletonData->SkeletonPositions[i].y;
	} 
}

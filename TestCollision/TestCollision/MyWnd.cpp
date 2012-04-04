#include "MyWnd.h"
#include "MyApp.h"
#include "mymath.h"





void MyWnd::OnCreate(){
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	glFrustum(-1.0f, +1.0f, -1.0f, +1.0f, 1.0f, 20.0f);
// 
// 	glMatrixMode(GL_MODELVIEW);
// 	glLoadIdentity();
// 
// 	glViewport(0,0,Width(),Height());
// 	glEnable(GL_DEPTH_TEST);
// 
// 	glClearColor(0.0f,0.0f,0.0f,0.0f);


}

void MyWnd::OnDisplay(){
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
	 // Camera
	 glLoadIdentity(); 
	 glTranslatef(0.0f, -5.0f, -7.0f);

	 // Frame
	 static unsigned long frameCount=0L;
	 glRasterPos2f(0.0f, 0.0f);
	 Printf("Frame = %lu", frameCount++);

	 if (_bToggleDisplay)
	 {glColor3f(1.0f,1.0f,1.0f);
	 } 
	 else
	 {glColor3f(1.0f,0.0f,0.0f);
	 }

	

}



#include "ChristmasGiftApp.h"




static ChristmasGiftApp theApp;

void ChristmasGiftApp::OnCreate()
{
	window.Show();
	//win1.Show();
	if(!window.HasExtension("GL_ARB_vertex_buffer_object") )
	{
		MsgPrintf("Vertex buffer object extension not found\n");
	}

}

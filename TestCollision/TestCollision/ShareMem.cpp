#include "ShareMem.h"


SpringLine::SpringLine(void)
{
	type = 0;
	isvisiable = false;

	//add two empty points

	r = 1.0f;
	g = 1.0f;
	b = 1.0f;

	fMass = 0.0f;


	/************************************************************************/
	/* set spring line initialize position                                                                     */
	/************************************************************************/
	sp.x = 2.0f;
	sp.y = 2.0f;	
	ep.x = 2.0f;
	ep.y = 2.0f;


}

ShareMem::ShareMem()
{
	mutex=CreateMutex(NULL,FALSE,"mymutex");
	/*assert(mutex!=NULL);*/
	left_hold =false;

	springLine = new SpringLine();

	mouse_x = mouse_y=2.0f;
}


ShareMem::~ShareMem()
{
	CloseHandle(mutex);
}

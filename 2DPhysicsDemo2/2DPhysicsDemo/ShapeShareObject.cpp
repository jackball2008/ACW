#include "ShapeShareObject.h"


ShapeShareObject::ShapeShareObject(void)
{
	mutex = CreateMutex(NULL, FALSE, "shapeMutes");
	last_left_down = false;
	left_down = false;
	left_hold = false;


	//spring
	springLine = new SpringLine();
	/************************************************************************/
	/* set initialize position                                                                     */
	/************************************************************************/
	YPoint sp;
	sp.x = 2.0f;
	sp.y = 2.0f;
	YPoint ep;
	ep.x = 2.0f;
	ep.y = 2.0f;
	springLine->points.push_back(sp);
	springLine->points.push_back(ep);

	mouse_x  = mouse_y = 2.0f;
	
}


ShapeShareObject::~ShapeShareObject(void)
{
	CloseHandle(mutex);
}





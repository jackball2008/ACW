#include "ShapeShareObject.h"


ShapeShareObject::ShapeShareObject(void)
{
	mutex = CreateMutex(NULL, FALSE, "shapeMutes");
// 	last_left_down = false;
// 	left_down = false;
	left_hold = false;


	//spring
	springLine = new SpringLine();
	/************************************************************************/
	/* set initialize position                                                                     */
	/************************************************************************/
	

	mouse_x  = mouse_y = 2.0f;

	shape_id_index = -99;

	paused = false;
	
}


ShapeShareObject::~ShapeShareObject(void)
{
	CloseHandle(mutex);
}





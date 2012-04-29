#include "ShapeShareObject.h"


ShapeShareObject::ShapeShareObject(void)
{
	mutex = CreateMutex(NULL, FALSE, "shapeMutes");
	last_left_down = false;
	left_down = false;
	left_hold = false;


	//spring
	springLine = new SpringLine();
	YPoint sp;
	sp.x = 2.0f;
	sp.y = 2.0f;
	YPoint ep;
	ep.x = 2.0f;
	ep.y = 2.0f;
	springLine->points.push_back(sp);
	springLine->points.push_back(ep);
	
}


ShapeShareObject::~ShapeShareObject(void)
{
	CloseHandle(mutex);
}





#include "ShapeShareObject.h"


ShapeShareObject::ShapeShareObject(void)
{
	mutex = CreateMutex(NULL, FALSE, "shapeMutes");
	last_left_down = false;
	left_down = false;
	left_hold = false;


	//spring
	springLine = new SpringLine();
	vec2f sp;
	sp.x = 2.0f;
	sp.y = 2.0f;
	vec2f ep;
	ep.x = 2.0f;
	ep.y = 2.0f;
	springLine->SetData(sp,ep);

	//ground
	ground = new Line();
	vec2f p1;
	p1.x = -1.0f;
	p1.y = -0.9f;
	vec2f p2;
	p2.x = 1.0f;
	p2.y = -0.9f;
	vec2f lmid;
	lmid.x = (p1.x + p2.x) / 2;
	lmid.y = (p1.y + p2.y) / 2;
	ground->SetData(p1,p2);
	ground->middlepoint = lmid;
}


ShapeShareObject::~ShapeShareObject(void)
{
	CloseHandle(mutex);
}





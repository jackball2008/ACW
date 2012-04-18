#pragma once
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Line.h"
#include "SpringLine.h"
#include <Windows.h>

class ShapeShareObject
{
private:
	HANDLE mutex;

public:
	vector<Shape*>renderObjects;
	/************************************************************************/
	/* mouse                                                                      */
	/************************************************************************/
	/*float u,v,old_u,old_v;*/

	bool left_down/*, right_down*/;
	bool last_left_down;

	bool left_hold;

	vec2f mouseposition;
	/*Point record_mouseposition;*/
	/*Point old_mouseposition;*/
	vec2f springstartp;
	vec2f springendp;


	//spring
	SpringLine *springLine;
	//ground
	Shape* ground;

public:
	ShapeShareObject(void);
	~ShapeShareObject(void);

	//void SetData(const Shape&);

	//vector<Shape*> GetData() const { return renderObjects;};
	/************************************************************************/
	/* wait for mutex                                                                     */
	/************************************************************************/
	inline bool Acquire(){
		return (WaitForSingleObject(mutex,5000L) == WAIT_OBJECT_0);
	};
	/************************************************************************/
	/* release mutex                                                                     */
	/************************************************************************/
	inline void Release(){
		ReleaseMutex(mutex);
	};
};


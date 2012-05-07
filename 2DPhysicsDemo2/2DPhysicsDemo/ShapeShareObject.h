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
	float mouse_x,mouse_y;


	bool left_hold;

	
	
// 	YPoint springstartp;
// 	YPoint springendp;


	//spring
	SpringLine *springLine;
	//ground
	Shape* ground;

public:
	ShapeShareObject(void);
	~ShapeShareObject(void);

	

	
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


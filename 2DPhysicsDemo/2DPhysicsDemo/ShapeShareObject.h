#pragma once
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Line.h"
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

	Point mouseposition;
	/*Point record_mouseposition;*/
	/*Point old_mouseposition;*/
	Point springstartp;
	Point springendp;

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


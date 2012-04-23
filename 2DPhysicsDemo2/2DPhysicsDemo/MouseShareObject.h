#pragma once
#include <iostream>
using namespace std;
#include <Windows.h>


class MouseShareObject
{
private:
	HANDLE mutex;
public:
	float u,v,old_u,old_v;

	bool left_down, right_down;

	

	

public:
	MouseShareObject(void);
	~MouseShareObject(void);



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


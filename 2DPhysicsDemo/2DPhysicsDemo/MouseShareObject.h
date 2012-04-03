#pragma once
#include <iostream>
using namespace std;
#include <Windows.h>

struct MouseInfo{
	float current_x, current_y;
	bool  isleft_dwon,isright_down;
	float speed;

public:
	MouseInfo(){
		current_x = 0.0f;
		current_y = 0.0f;
		speed = 0.0f;
		isleft_dwon = false;
		isright_down = false;
	}
};

class MouseShareObject
{
public:
	float u,v,old_u,old_v;

	bool left_down, right_down;

	//MouseInfo _mouseinfo;

	HANDLE mutex;

public:
	MouseShareObject(void);
	~MouseShareObject(void);

// 	void SetMousePosition(const float&u, const float&v);
// 	void SetMouseButton(const int&lr, const bool&down);

// 	const MouseInfo& GetMouseCurrentInfo (){
// 		return _mouseinfo;
// 	}

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


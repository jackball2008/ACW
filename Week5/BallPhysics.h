#pragma once

#include "GXBase.h"
using namespace gxbase;

class BallPhysics
{
private:
	float _height;
	float _velocity;
	const float _gravity;

	bool _terminate;

	HANDLE _hThread;	

	void update();

	static unsigned __stdcall threadFunc(void *param) {
		if (param)
			return ((BallPhysics*)param)->run();
		return 1;  // Return error
	}

	int run();

	CRITICAL_SECTION cs;

public:
	BallPhysics() :
		_gravity (-9.8f),
		_height (0.0f),
		_velocity (15.0f),
		_terminate (false),
		_hThread (0)
	{}

	float height() const { 
		return _height;
	}

	void terminate() {
		_terminate = true;
	}

	HANDLE start();

	void waitForTermination();
};

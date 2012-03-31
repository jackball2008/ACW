#include "ballphysics.h"
#include <cmath>
#include <process.h>

#include "MyApp.h"

void BallPhysics::update() {
	// CARE: GetDeltaTime is not thread safe
	float deltaT = (float)App::GetDeltaTime();
	float newHeight = _height + _velocity * deltaT + 0.5f * _gravity * deltaT * deltaT;
	
	if (newHeight < 0.0) { //Collision has occurred

		// Solve quadratic
		float a = _gravity;
		float b = _velocity;
		float c = _height;
		float s = b*b - 4.0f*a*c;
		s = (s>0.0f ? sqrt(s) : 0.0f);
		float t1 = (-b + s) / (2.0f * a);
		float t2 = (-b - s) / (2.0f * a);
		float collisionT = (t1 > t2 ? t1 : t2);

		// Check --- height should be zero
		newHeight = _height + _velocity * collisionT + 0.5f * _gravity * collisionT * collisionT;

		// At collision
		_velocity = _velocity + _gravity * collisionT;
		_velocity = -_velocity;

		// Bounce
		deltaT -= collisionT;
		newHeight = _velocity * deltaT + 0.5f * _gravity * deltaT * deltaT;
	}
	_velocity += _gravity * deltaT;
	_height = newHeight;
}

int BallPhysics::run() {
	// CARE: GetDeltaTime is not thread safe
	App::GetDeltaTime();
	while(!_terminate) {
		update();
		Sleep(25);
	}
	return 0;
}

HANDLE BallPhysics::start() {
    unsigned threadId=0;
	_hThread = (HANDLE)_beginthreadex(
		NULL,		// no security attributes (child cannot inherited handle)
		1024*1024,	// 1MB stack size
		threadFunc,	// code to run on new thread
		this,		// pointer to host application class
		0,			// run immediately (could create suspended)
		&threadId	// OUT: returns thread ID
	);
	return _hThread;
}

void BallPhysics::waitForTermination() {
	// wait for it to stop
	WaitForSingleObject(_hThread, INFINITE);
	// close thread handle
	CloseHandle(_hThread);
	_hThread=0;
}

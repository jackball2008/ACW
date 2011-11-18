#pragma once
#include <GXBase.h>
using namespace gxbase;

class Vector3f {
private:
	GLfloat _xyz[3];

public:
	int size() const { return 3;}

	void Assign(GLfloat x, GLfloat y, GLfloat z) {
		_xyz[0] = x;
		_xyz[1] = y;
		_xyz[2] = z;
		
	}

	Vector3f() { 
		Assign(0.0, 0.0, 0.0);
	}

	Vector3f(GLfloat x, GLfloat y, GLfloat z) {
		Assign(x, y, z);
	}

	Vector3f(GLfloat xyz[]) {
		Assign(xyz[0], xyz[1], xyz[2]);
	}

	const GLfloat* xyz() const {
		return _xyz;
	}

	const float& operator[](int i) const {
		return _xyz[i];
	}

	float& operator[](int i) {
		return _xyz[i];
	}




};
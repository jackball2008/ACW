#pragma once
#include <GXBase.h>

using namespace gxbase;



class Color {
private:
	GLfloat _rgba[4];

public:
	void Assign(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
		_rgba[0] = r;
		_rgba[1] = g;
		_rgba[2] = b;
		_rgba[3] = a;
	}

	Color() { 
		Assign(0.0, 0.0, 0.0, 0.0);
	}

	Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
		Assign(r, g, b, a);
	}

	Color(GLfloat rgba[]) {
		Assign(rgba[0], rgba[1], rgba[2], rgba[3]);
	}

	const GLfloat* rgba() const {
		return _rgba;
	}

	static Color black() {
		return Color(0.0, 0.0, 0.0, 1.0);
	}

	static Color white() {
		return Color(1.0, 1.0, 1.0, 1.0);
	}

	static Color red() {
		return Color(1.0, 0.0, 0.0, 1.0);
	}

	static Color green() {
		return Color(0.0, 1.0, 0.0, 1.0);
	}

	static Color blue() {
		return Color(0.0, 0.0, 1.0, 1.0);
	}

	static Color yellow() {
		return Color(1.0, 1.0, 0.0, 1.0);
	}

	static Color null() {
		return Color(0.0, 0.0, 0.0, 0.0);
	}

	const float& operator[](int i) const {
		return _rgba[i];
	}

	float& operator[](int i) {
		return _rgba[i];
	}
};

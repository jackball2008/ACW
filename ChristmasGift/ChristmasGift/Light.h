#include <GXBase.h>
#include "Color.h"
#include "Vector4f.h"
using namespace gxbase;

class Lights {
private:
	// Light number
	GLuint _lightNumber;				

	// Ambient, diffuse and position
	Color _ambient;
	Color _diffuse;
	Vector4f _position, _direction;
	GLfloat _cutoff;
	GLfloat _exponent;

public:
	Lights() {
		_lightNumber = -1;
	}

	void create(GLuint lightNum, const Color &ambient=Color::black(), const Color &diffuse=Color::white(), const Vector4f &position=Vector4f(0.0f,0.0f,0.0f,1.0f)) {
		// the light being defined
		_lightNumber = lightNum;	

		setAmbient(ambient);
		setDiffuse(diffuse);
		setPosition(position);
	}

	void setAmbient(const Color &ambient) {
		_ambient = ambient;
		glLightfv(GL_LIGHT0+_lightNumber, GL_AMBIENT, _ambient.rgba());
	}		

	void setDiffuse(const Color &diffuse) {
		_diffuse = diffuse;
		glLightfv(GL_LIGHT0+_lightNumber, GL_DIFFUSE, _diffuse.rgba());
	}		

	void setPosition(const Vector4f &position) {
		_position = position;
		glLightfv(GL_LIGHT0+_lightNumber, GL_POSITION, _position.xyzw());
	}

	void setDirection(const Vector4f &direction) {
		_direction = direction;
		glLightfv(GL_LIGHT0+_lightNumber, GL_SPOT_DIRECTION, _direction.xyzw());
	}

	void setSpot(const GLfloat &cutoff, const GLfloat &exponent) {
		_cutoff = cutoff;
		_exponent = exponent;
		glLightf(GL_LIGHT0+_lightNumber,GL_SPOT_CUTOFF, cutoff);
		glLightf(GL_LIGHT0+_lightNumber,GL_SPOT_EXPONENT, exponent);
	}

	void apply() {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0 + _lightNumber);
	}

	const float& operator[](int i) const {
		return _position[i];
	}

	float& operator[](int i) {
		return _position[i];
	}


	

};
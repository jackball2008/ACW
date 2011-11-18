#include <GXBase.h>

using namespace gxbase;

class Sphere {
private:
	GLUquadric *_obj;
	GLfloat _radius;
	GLuint _slices, _stacks;

public:	 
	Sphere() { 
		_obj = NULL;
	}

	~Sphere() {
		gluDeleteQuadric(_obj);
	}

	void create(GLfloat radius, GLuint slices, GLuint stacks, bool texture) {
		_obj = gluNewQuadric();
		gluQuadricNormals(_obj, GLU_SMOOTH);
		_radius = radius;
		_slices = slices;
		_stacks = stacks;
		gluQuadricTexture(_obj, texture);
	}


	void draw() const {
		if (_obj)
			gluSphere(_obj, _radius, _slices, _stacks);
	}
};
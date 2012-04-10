#include <GXBase.h>
using namespace gxbase;

struct Force{
	float dx;
	float dy;
	float energy;

	float sx;
	float sy;

public:
	Force(){
		dx = 0;
		dy = 0;
		energy = 0;

		sx = 0;
		sy = 0;
	}
};
#include <GXBase.h>
using namespace gxbase;
#include <vector>
using namespace std;

struct Point{
	float x;
	float y;
public:
	Point(){
		x=0;y=0;
	};

	Point(const float& _x, const float& _y){
		x = _x;
		y = _y;
	};
};


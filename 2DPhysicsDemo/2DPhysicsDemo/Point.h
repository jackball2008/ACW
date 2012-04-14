#include <GXBase.h>
using namespace gxbase;
#include <vector>
using namespace std;

struct YPoint{
	float x;
	float y;
public:
	YPoint(){
		x=0;y=0;
	};

	YPoint(const float& _x, const float& _y){
		x = _x;
		y = _y;
	};
};
struct   YLineSeg{   
	YPoint   a,b;   
}; 


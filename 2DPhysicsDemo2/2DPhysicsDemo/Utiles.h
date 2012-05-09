#include <math.h>
#include <vector>
#include "Point.h"

using namespace std;

class Utiles{
public:
	static float Mul(const YPoint& p1, const YPoint& p2, const YPoint& p0){
		return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)); 
	};
	static float Dis(const YPoint& p, const float& x, const float& y){
		return sqrt((p.x - x)*(p.x-1)+(p.y-y)*(p.y-y));
	};
};


#include <math.h>
#include <vector>
#include "Point.h"

using namespace std;

static float Mul(const Point& p1, const Point& p2, const Point& p0){
	return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)); 
};
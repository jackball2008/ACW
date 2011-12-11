#pragma once
#include <iostream>

using std::cout;
using std::endl;
///////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* store all staff in the ball as  a scene                                                                     */
/************************************************************************/

enum WORLD_SEASON { SPRING, SUMMBER, AUTUMN, WINTER };

class SnowWorld
{
public:
	SnowWorld(void);
	~SnowWorld(void);


	void CreateWorld();


	void Draw();


	void IncreaseRunningSpeed();

	void ReduceRunningSpeed();

	int season;




};


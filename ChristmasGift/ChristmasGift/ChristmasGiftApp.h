#pragma once
#include <GXBase.h>
#include "ChristmasWindow.h"
//#include "SnowWorldWindow.h"

using namespace gxbase;



class ChristmasGiftApp: public App
{

public:
	ChristmasWindow window;
	//SnowWorldWindow win1;

	void OnCreate();
};


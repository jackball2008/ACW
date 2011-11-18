#pragma once
#include <GXBase.h>
#include "ChristmasWindow.h"

using namespace gxbase;



class ChristmasGiftApp: public App
{

public:
	ChristmasWindow window;

	void OnCreate();
};


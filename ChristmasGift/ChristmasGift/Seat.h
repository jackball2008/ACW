#pragma once
#include "DisplayObjectModel.h"

#include <ctime>
class Seat :
	public DisplayObjectModel
{
public:
	Seat(void);
	~Seat(void);

	void Update(const float& t);
	void Draw();


	GLuint seat_texture_ID;
	GLuint seat_snow_texture_ID;
	
};


#pragma once
class ISprite
{
public:
	virtual void UpDate() = 0;
	virtual void Draw() = 0;
	virtual void InitializeData()=0;
	virtual void CreateVBO() = 0;
};
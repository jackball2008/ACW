#include "SayHello.h"


SayHello::SayHello(void)
{
}


SayHello::~SayHello(void)
{
}


void SayHello::DisplayHelloMessage() const
{
	MessageBoxA(0,"HELLO World","", MB_OK);
}
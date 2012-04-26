#include "ShareMem.h"


ShareMem::ShareMem()
{
	mutex=CreateMutex(NULL,FALSE,"mymutex");
	assert(mutex!=NULL);
}


ShareMem::~ShareMem()
{
	CloseHandle(mutex);
}

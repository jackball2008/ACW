/**
This is a __declspec extended attribute.

This form of __declspec can be applied to any class declaration, but should only be applied to pure interface classes, that is, classes that will never be instantiated on their own. The __declspec stops the compiler from generating code to initialize the vfptr in the constructor(s) and destructor of the class. In many cases, this removes the only references to the vtable that are associated with the class and, thus, the linker will remove it. Using this form of __declspec can result in a significant reduction in code size.

If you attempt to instantiate a class marked with novtable and then access a class member, you will receive an access violation (AV).
*/
#define MXYGameEngineInterface class __declspec(novtable)
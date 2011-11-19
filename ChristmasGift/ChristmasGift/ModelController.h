#pragma once


#include <Image.h>

#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include <math.h>
#include <GXBase.h>

#include "IController.h"
#include "IDisplayObject.h"


using namespace std;
/*using namespace gxbase;*/

class ModelController:public IController
{
public:
	ModelController(void);
	~ModelController(void);

	Image _images[5];
	GLuint _textures[5];
	
	static ModelController* GetInstance();

	void AssemblyModelFromFile(IDisplayObject*, const char*, GLuint texarr);

	void AssemblyModelFromHeightFieldFile(IDisplayObject*, const char* mappath,GLuint texarr);

	void AssemblyModelFromHeightFieldFile2(IDisplayObject*, const char* mappath,GLuint texarr);

	void AssemblyTransparencyPartSphere(IDisplayObject*,GLfloat radius, int slices, int stacks, GLuint texarr);

	void AssemblyBasicTreeData(IDisplayObject*,GLfloat radius, int slices, int stacks);

	void LoadTexture();

	

private:
	static ModelController _modelController;


};


#pragma once
#include "glex.h"
#include "Vertex.h"
#include "Materials.h"

// Location/Normals
#define X_POS 0
#define Y_POS 1
#define Z_POS 2
// Texture Coordinates
#define U_POS 0
#define V_POS 1
// Colours
#define R_POS 0
#define G_POS 1
#define B_POS 2
#define A_POS 3

#define Interface class __declspec(novtable)

Interface IDisplayObject : public glex
{
public:

	virtual void Initialize();

	//update and draw are the most important method
	virtual void Update(const float& t);

	virtual void Draw();

	virtual void setVertexes(Vertex (*_vertices), GLuint (*_indicesaddr),const int& numofvertex,const int& numofindex, const GLuint& texarr, const GLenum& drawtype);
	
	virtual void setTreeParameter();

	virtual void setRenderTexture(bool &v);

	virtual void setRenderMaterials(bool &v);

	virtual void setMaterials(Materials& m);

	virtual Materials* getMaterials();

	virtual void setEnableTransparency(const bool& en=false);

	virtual bool getEnableTransparency();

	virtual void setColorApalha(float v);

	virtual float getColorApalha();

	virtual void setEnableCullFront(bool v);

	virtual void setEnableCullBack(bool v);
	

};




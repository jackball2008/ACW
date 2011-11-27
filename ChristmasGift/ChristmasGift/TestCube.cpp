#include "TestCube.h"


TestCube::TestCube(void)
{
}


TestCube::~TestCube(void)
{
}

void TestCube::Draw()
{
	
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboID);

	// Set the state of what we are drawing (I don't think order matters here, but I like to do it in the same 
	// order I set the pointers
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	/************************************************************************/
	/* texture render control                                                                     */
	/************************************************************************/
	if(_renderTextures){
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textures);
	}

	// Resetup our pointers.  This doesn't reinitialise any data, only how we walk through it
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(20));
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));

	if(_enableTransparency){
		glDisable( GL_CULL_FACE );
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	}	

	if(_renderMaterials){
		_materials.apply();
	}

	if(_enableCullFront){
		glEnable(GL_CULL_FACE);
	}

	if(_enableCullBack){
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
	}



	// work for model from blender
	if(GL_TRIANGLES == _drawtype)
		glDrawElements(GL_TRIANGLES, _numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	if(GL_TRIANGLE_STRIP == _drawtype)
		glDrawElements(GL_TRIANGLE_STRIP, _numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));


	/************************************************************************/
	/* shader end                                                                     */
	/************************************************************************/
	if(_enableCullBack){
		glDisable(GL_CULL_FACE);
	}

	if(_enableCullFront){
		glDisable(GL_CULL_FACE);
	}
	if(_enableTransparency){
		glDisable(GL_BLEND);
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

	}

	// Disable our client state back to normal drawing
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

#include "Pool.h"


Pool::Pool(void)
{
}


Pool::~Pool(void)
{
}

void Pool::Update(const float& t){

}

void Pool::Draw(){

	//glColor3f(1,1,1);
	glUseProgram(/*shaderProgramID*/0);

	glPushMatrix();
/*	glRotatef(rotaterangle,rotatex,rotatey,rotatez);*/

	/*DisplayObjectModel::Draw();*/
	/************************************************************************/
	/* override                                                                     */
	/************************************************************************/
	//glEnable(GL_LIGHTING);

	/************************************************************************/
	/* texture                                                                     */
	/************************************************************************/
// 	glActiveTexture(GL_TEXTURE1);
// 	glEnable(GL_TEXTURE_2D); 
// 	glBindTexture(GL_TEXTURE_2D, permTextureID);

	// 	glActiveTexture(GL_TEXTURE1);
	// 	glEnable(GL_TEXTURE_2D); 
	// 	glBindTexture(GL_TEXTURE_2D, simplexTextureID);
	// 
	// 	glActiveTexture(GL_TEXTURE2);
	// 	glEnable(GL_TEXTURE_2D); 
	// 	glBindTexture(GL_TEXTURE_2D, gradTextureID);

// 	glActiveTexture(GL_TEXTURE0);
// 	glEnable(GL_TEXTURE_2D); 
// 	glBindTexture(GL_TEXTURE_2D, seat_texture_ID);


	//bind vbo ibo
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	//set texture coordinate
	//texture
// 	glClientActiveTexture(GL_TEXTURE0);
// 	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
// 	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));

	// 	glClientActiveTexture(GL_TEXTURE1);
	// 	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	// 	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	// 
	// 	glClientActiveTexture(GL_TEXTURE2);
	// 	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	// 	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));

// 	glClientActiveTexture(GL_TEXTURE1);
// 	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
// 	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));



	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(20));
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);


	glDrawElements(GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));



/*	glDisable(GL_TEXTURE_2D);*/

// 	glClientActiveTexture(GL_TEXTURE0);
// 	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

// 	glClientActiveTexture(GL_TEXTURE1);
// 	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	// 	glClientActiveTexture(GL_TEXTURE2);
	// 	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	// 
	// 	glClientActiveTexture(GL_TEXTURE3);
	// 	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

// 	glActiveTexture(GL_TEXTURE0);
// 	glDisable(GL_TEXTURE_2D);
// 	glActiveTexture(GL_TEXTURE1);
// 	glDisable(GL_TEXTURE_2D);
	// 	glActiveTexture(GL_TEXTURE2);
	// 	glDisable(GL_TEXTURE_2D);
	// 
	// 	glActiveTexture(GL_TEXTURE3);
	// 	glDisable(GL_TEXTURE_2D);


	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	/************************************************************************/
	/* end                                                                     */
	/************************************************************************/
	glPopMatrix();
	glUseProgram(0);


}

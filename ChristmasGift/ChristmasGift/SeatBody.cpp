#include "SeatBody.h"


SeatBody::SeatBody(void)
{
}


SeatBody::~SeatBody(void)
{
}

void SeatBody::Update(const float& t){

}
void SeatBody::Draw(){
	glPushMatrix();

// 	glTranslatef(translatex,translatey,translatez);
// 	glRotatef(rotaterangle,1,0,0);
// 	glScalef(scalex,scaley,scalez);

	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, textureID);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	glClientActiveTexture(GL_TEXTURE0);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(20));
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);


	glDrawElements(GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	glDisable(GL_TEXTURE_2D);

	glClientActiveTexture(GL_TEXTURE0);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE_2D);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	/************************************************************************/
	/* end                                                                     */
	/************************************************************************/
	glPopMatrix();
}
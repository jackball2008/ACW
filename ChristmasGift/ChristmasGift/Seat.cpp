#include "Seat.h"


Seat::Seat(void)
{
	//MakeNoiseTexture();
	initPermTexture(&permTextureID);
	initSimplexTexture(&simplexTextureID);
	initGradTexture(&gradTextureID);
}


Seat::~Seat(void)
{
}

void Seat::Update(const float& t){

}
void Seat::Draw(){
	

	glUseProgram(seat_shader_program_ID);
	glPushMatrix();
	glRotatef(rotaterangle,rotatex,rotatey,rotatez);

	/*DisplayObjectModel::Draw();*/
	/************************************************************************/
	/* override                                                                     */
	/************************************************************************/
	glEnable(GL_LIGHTING);

	/************************************************************************/
	/* texture                                                                     */
	/************************************************************************/
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, seat_snow_texture_ID);


	//bind vbo ibo
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	//set texture coordinate
	//texture
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
	glUseProgram(0);
}

void Seat::MakeNoiseTexture(){
	int width = 512;
	int height = 512;
	noise::module::Perlin perlinNoise;
	// Base frequency for octave 1.
	perlinNoise.SetFrequency(4.0);
	GLubyte *data = new GLubyte[ width * height * 4 ];
	double xRange = 1.0;
	double yRange = 1.0;
	double xFactor = xRange / width;
	double yFactor = yRange / height;

	for( int oct = 0; oct < 4; oct++ ) {
		perlinNoise.SetOctaveCount(oct+1);
		for( int i = 0; i < width; i++ ) {
			for( int j = 0 ; j < height; j++ ) {
				double x = xFactor * i;
				double y = yFactor * j;
				double z = 0.0;
				float val = (float)perlinNoise.GetValue(x,y,z);
				// Scale and translate to roughly between 0 and 1
				val = (val + 1.0f) * 0.5f;
				// Clamp strictly between 0 and 1
				val = val> 1.0f ? 1.0f :val;
				val = val< 0.0f ? 0.0f :val;
				// Store in texture
				data[((j * width + i) * 4) + oct] = 
					(GLubyte) ( val * 255.0f );
			}
		}
	}
	
	glGenTextures(1, &seat_snow_texture_ID);
	glBindTexture(GL_TEXTURE_2D, seat_snow_texture_ID);
// 	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,
// 		GL_UNSIGNED_BYTE,data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
		GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
		GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	delete [] data;
}

void Seat::UpdateNoise(){
	int width = 512;
	int height = 512;
	noise::module::Perlin perlinNoise;
	// Base frequency for octave 1.
	srand((unsigned)time(0));
	perlinNoise.SetFrequency(rand()%8);
	GLubyte *data = new GLubyte[ width * height * 4 ];
	double xRange = 1.0;
	double yRange = 1.0;
	double xFactor = xRange / width;
	double yFactor = yRange / height;

	for( int oct = 0; oct < 4; oct++ ) {
		perlinNoise.SetOctaveCount(oct+1);
		for( int i = 0; i < width; i++ ) {
			for( int j = 0 ; j < height; j++ ) {
				double x = xFactor * i;
				double y = yFactor * j;
				double z = 0.0;
				float val = (float)perlinNoise.GetValue(x,y,z);
				// Scale and translate to roughly between 0 and 1
				val = (val + 1.0f) * 0.5f;
				// Clamp strictly between 0 and 1
				val = val> 1.0f ? 1.0f :val;
				val = val< 0.0f ? 0.0f :val;
				// Store in texture
				data[((j * width + i) * 4) + oct] = 
					(GLubyte) ( val * 255.0f );
			}
		}
	}

	glBindTexture(GL_TEXTURE_2D, seat_snow_texture_ID);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,
		GL_UNSIGNED_BYTE,data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
		GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
		GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	delete [] data;
}
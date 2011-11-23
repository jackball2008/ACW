#include "ShaderDisplayObjectModel.h"


ShaderDisplayObjectModel::ShaderDisplayObjectModel(void)
{
}


ShaderDisplayObjectModel::~ShaderDisplayObjectModel(void)
{
}


void ShaderDisplayObjectModel::Initialize(){

}


void ShaderDisplayObjectModel::Update(const float& t){

}

void ShaderDisplayObjectModel::Draw(){

}

void ShaderDisplayObjectModel::setVertexes(Vertex (*_vertices), GLuint (*_indicesaddr),const int& numofvertex,const int& numofindex, const GLuint& texarr, const GLenum& drawtype){

}



void ShaderDisplayObjectModel::setRenderTexture(bool v){

}

void ShaderDisplayObjectModel::setRenderMaterials(bool v){

}

void ShaderDisplayObjectModel::setMaterials(Materials& m){

}

Materials* ShaderDisplayObjectModel::getMaterials(){
	


	return &_material;
}

void ShaderDisplayObjectModel::setEnableTransparency(bool en){
	_enabletransparency = en;
}

bool ShaderDisplayObjectModel::getEnableTransparency(){
	return _enabletransparency;
}

void ShaderDisplayObjectModel::setColorApalha(float v){
	_alpha = v;
}

float ShaderDisplayObjectModel::getColorApalha(){
	return _alpha;
}

void ShaderDisplayObjectModel::setEnableCullFront(bool v){

}

void ShaderDisplayObjectModel::setEnableCullBack(bool v){

}

void ShaderDisplayObjectModel::setEnableShaderProgram(bool b){

}

void ShaderDisplayObjectModel::setShaderProgramID(GLuint id){

}
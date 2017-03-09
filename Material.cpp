//
// Created by abijosh on 10/9/16.
//

#include "Material.h"


Material::Material(Animation <unsigned int> *textureIDs, Shader* ShaderPtr)
	: textureIDs(textureIDs)
	, ShaderPtr(ShaderPtr)
{
	isAnimated = true;
	textureID = textureIDs->getKeyFrame(0.0f);
}

Material::Material(unsigned int textureID, Shader* ShaderPtr)
	: textureIDs(nullptr)
	, textureID(textureID)
	, ShaderPtr(ShaderPtr)
{
	isAnimated = false;
}

Material::~Material()
{
}

Shader* Material::getShaderPointer(){
	return ShaderPtr;
}

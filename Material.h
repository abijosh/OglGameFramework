#ifndef MATERIAL_H
#define MATERIAL_H

#include <vector>
#include "Shader.h"
#include "Animation.h"

class Material
{
public:
	Material(Animation <unsigned int> *textureIDs, Shader* ShaderPtr);
	Material(unsigned int textureID, Shader* shaderPtr);
	~Material();

	unsigned int getTextureID() { return textureID; }
	Shader* getShaderPointer();

	void updateTexture(float timePassed){
		if (isAnimated)
			textureID = textureIDs->getKeyFrame(timePassed);
	}

private:
	bool isAnimated;
	unsigned int textureID;
	Animation <unsigned int> *textureIDs;
	Shader* ShaderPtr;
};

#endif //MATERIAL_H
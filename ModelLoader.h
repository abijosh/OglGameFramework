#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <vector>
#include <iosfwd>
#include <string>

#include "Animation.h"
#include "RawModel.h"
#include "Shader.h"
#include "Material.h"
#include "TexturedModel.h"
#include "BufferLoader.h"
#include "Entity.h"

struct texturedModelData{
	texturedModelData(std::string fileName, const int width, const int height)
		:fileName(fileName), width(width), height(height)
	{}
	std::string fileName;
	int width, height;
};

typedef std::pair<std::string, TexturedModel*> textureReference;

class ModelLoader
{
public:
	ModelLoader();
	~ModelLoader();

	Entity* loadModel(const std::string filename);
	Entity* loadAnimatedModel(std::string fileLocation, unsigned int count, float maxDuration);
	Shader* getBasicShader(){ return ShaderPtr; }

	void createBasicShader();
	void freeMemory();


private:
	TexturedModel* createTexturedQuad(float width, float height, Material* MaterialPtr);

private:
	BufferLoader bufferLoader;
	Shader* ShaderPtr;
	std::vector<Entity*> Entities;
	std::vector<textureReference> loadedTextures;
};


#endif //MODEL_LOADER_H
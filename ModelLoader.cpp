//
// Created by abijosh on 10/9/16.
//

#include "ModelLoader.h"


ModelLoader::ModelLoader()
{
}

ModelLoader::~ModelLoader()
{
}

Entity* ModelLoader::loadModel(const std::string fileName){
	Entity* retVal = nullptr;
	for (auto loadedTex : loadedTextures){
		if (loadedTex.first == fileName){
			retVal = new Entity(loadedTex.second, glm::vec3(0.0f), glm::vec3(1.0f));
			return retVal;
		}
	}
	int width, height;
	int textureID = bufferLoader.loadTexture(&fileName[0], &width, &height);
	if (textureID >= 0) {
		TexturedModel* texturedQuad = createTexturedQuad((float)width / 20.0f, (float)height / 20.0f, new Material(textureID, ShaderPtr));
		textureReference newTexModel(fileName, texturedQuad);
		loadedTextures.push_back(newTexModel);

		retVal = new Entity(texturedQuad, glm::vec3(0.0f), glm::vec3(1.0f));

		Entities.push_back(retVal);
	}
	return retVal;
}

void ModelLoader::createBasicShader() {
	ShaderPtr = new Shader();
	ShaderPtr->createShader("./shaders/vs.mvp.glsl", "./shaders/fs.mvp.glsl");
}

TexturedModel* ModelLoader::createTexturedQuad(float halfWidth, float halfHeight, Material* MaterialPtr) {

	std::vector<float> positions;
	std::vector<float> uv;
	std::vector<int> indices;

	//left top triangle
	positions.push_back(-halfWidth);
	positions.push_back(-halfHeight);
	positions.push_back(0);

	uv.push_back(0);
	uv.push_back(1);

	positions.push_back(-halfWidth);
	positions.push_back(halfHeight);
	positions.push_back(0);

	uv.push_back(0);
	uv.push_back(0);

	positions.push_back(halfWidth);
	positions.push_back(halfHeight);
	positions.push_back(0);

	uv.push_back(1);
	uv.push_back(0);

	positions.push_back(halfWidth);
	positions.push_back(-halfHeight);
	positions.push_back(0);

	uv.push_back(1);
	uv.push_back(1);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);

	RawModel* RawModelPtr = bufferLoader.loadToBuffer(positions, uv, indices);

	positions.clear();
	uv.clear();
	indices.clear();

	return new TexturedModel(RawModelPtr, MaterialPtr);
}

void ModelLoader::freeMemory() {
	delete ShaderPtr;
	bufferLoader.freeBuffer();
	for (Entity* e : Entities) {
		e->~Entity();
		delete e;
	}
}

Entity *ModelLoader::loadAnimatedModel(std::string fileLocation, unsigned int count, float maxDuration) {

	int width, height;
	std::vector<unsigned int> textures;
	for (unsigned int i = 0; i < count; ++i) {
		std::string fileName = fileLocation + std::to_string(i + 1) + ".png";
		textures.push_back(bufferLoader.loadTexture(&fileName[0], &width, &height));
	}
	Animation<unsigned int> *animation = new Animation<unsigned int>(maxDuration, textures);
	animation->setPlayMode(Animation<unsigned int>::LOOP);
	TexturedModel* texturedQuad = createTexturedQuad((float)width / 20.0f, (float)height / 20.0f, new Material(animation, ShaderPtr));

	Entity* retVal = new Entity(texturedQuad, glm::vec3(0.0f), glm::vec3(1.0f));

	Entities.push_back(retVal);
	return retVal;
}

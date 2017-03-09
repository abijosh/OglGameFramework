#ifndef BUFFER_LOADER_H
#define BUFFER_LOADER_H

#include "Header.h"

#include "RawModel.h"

class BufferLoader
{
public:
	BufferLoader();
	~BufferLoader();

	RawModel* loadToBuffer(std::vector<float> positions, std::vector<float> uv, std::vector<int> indices);
	unsigned int loadTexture(const char* filename, int *width, int *height);
	void freeBuffer();

private:
	unsigned int createVAO();
	void storeToVBO(std::vector<float> data, unsigned int length, unsigned int index);
	void storeElementsToVBO(std::vector<int> indices);
	void unbindVAO();

private:
	std::vector<unsigned int> vboList, vaoList, textureList;

};

#endif //BUFFER_LOADER_H
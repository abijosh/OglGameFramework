#ifndef TEXTURED_MODEL_H
#define TEXTURED_MODEL_H

#include "RawModel.h"
#include "Material.h"

class TexturedModel
{
public:
	TexturedModel(RawModel* RawModelPtr, Material* MaterialPtr);
	~TexturedModel();

	RawModel* getRawModel();
	Material* getMaterial();

private:
	RawModel* mp_RawModel;
	Material* mp_Material;
};

#endif //TEXTURED_MODEL_H
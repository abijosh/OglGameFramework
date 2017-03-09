#ifndef RAW_MODEL_H
#define RAW_MODEL_H

class RawModel
{
public:
	RawModel(unsigned int vaoID, unsigned int faceCount);
	~RawModel();

	unsigned int getVaoID();
	unsigned int getFaceCount();

private:
	unsigned int m_vaoID;
	unsigned int m_faceCount;
};

#endif //RAW_MODEL_H
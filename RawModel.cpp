//
// Created by abijosh on 10/9/16.
//

#include "RawModel.h"


RawModel::RawModel(unsigned int vaoID, unsigned int faceCount)
{
	this->m_vaoID = vaoID;
	this->m_faceCount = faceCount;
}


RawModel::~RawModel()
{
}

unsigned int RawModel::getVaoID(){
	return m_vaoID;
}

unsigned int RawModel::getFaceCount(){
	return m_faceCount;
}
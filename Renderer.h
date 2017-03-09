#ifndef RENDERER_H
#define RENDERER_H

#include "Header.h"

#include "Camera.h"
#include "RawModel.h"
#include "Shader.h"
#include "Material.h"
#include "TexturedModel.h"
#include "Entity.h"
#include "Scene.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void setWindowPointer(GLFWwindow* windowPointer);
	void initializeCamera(int windowWidth, int windowHeight);
	Camera* getCamera();

    void setAspectRatio(float aspectRatio);
	void prepare();
	void postRender();
	void renderScene(Scene* EntityPointer);
private:
	void renderEntity(Entity* EntityPointer);
	void updateShaderLocationValues(Entity* EntityPointer);


private:
	GLFWwindow* mp_window;
	Camera *m_pCamera;
	float m_red, m_green, m_blue, m_alpha;
};

#endif //RENDERER_H
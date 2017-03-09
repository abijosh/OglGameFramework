#ifndef ICAT_GAME_H
#define ICAT_GAME_H

#include "Header.h"

#include "ModelLoader.h"
#include "Entity.h"
#include "Scene.h"
#include "DisplayManager.h"
#include "UserInteraction.h"
#include "Renderer.h"


class IcatGame
{
public:
	IcatGame();
	~IcatGame();

	bool initializeWindow(int width = 1280, int height = 720, const char* title = "Icat IM OGL Wrapper Library");
	bool ifWindowShouldClose(){ return displayManager.isCloseRequested(); }
	void terminate();

	Entity* createEntity(const char* filename);

	void windowCallBack(GLFWwindow* window, int width, int height){
		renderer.setAspectRatio((float)width / (float)height);
	}
	
	float getDeltaTime(){ return deltaTime; }
	float getElapsedTime(){ return glfwGetTime(); }

	void setScenePtr(Scene* scenePtr)	{	this->scenePtr = scenePtr;	}
	void updateWindow();

private:
	void freeResources();

private:
	float prevTime{ 0.0f }, deltaTime{ 0.0f };
	DisplayManager displayManager;
	ModelLoader modelLoader;
	Renderer renderer;
	UserInteraction oUserInteraciton;
	Scene *scenePtr;
};


#endif //ICAT_GAME_H
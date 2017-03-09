#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "Header.h"
class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();

	bool createDisplay(int width, int height, const char* title);
	GLFWwindow* getWindowPointer();
	void setCurrentContext();
	bool isCloseRequested();
	void closeWindow();
	void pollEvents();

	void update(float deltaTime);

private:
	int WIDTH, HEIGHT;
	GLFWwindow* m_pWindow;
};

#endif //DISPLAY_MANAGER_H
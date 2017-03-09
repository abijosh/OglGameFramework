#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

class UserInteraction {
public:
	UserInteraction();
	~UserInteraction();

	static void keyEvent(GLFWwindow* window, int key, int scancode, int action, int mode);

	static bool left, right, up, down, space, escape, mouseLeftButtonDown, mouseRightButtonDown;
	static int width, height;
	static double lastLeftMouseClickX, lastLeftMouseClickY, lastLeftMouseReleaseX, lastLeftMouseReleaseY;
	static double lastRightMouseClickX, lastRightMouseClickY, lastRightMouseReleaseX, lastRightMouseReleaseY;
	static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

};

#endif //USER_INTERACTION_H
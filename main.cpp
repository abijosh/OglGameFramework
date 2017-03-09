//
// Created by abijosh on 10/9/16.
//

#include "IcatGame.h"


IcatGame icatGame;

void initGame(){
	Entity* icatLogo = icatGame.createEntity("./assets/Icat.png");
	icatLogo->setPosition(64.0f, 36.0f, 0.0f);

	Scene *scene = new Scene();
	scene->addEntity(icatLogo);
	icatGame.setScenePtr(scene);
}

int main(){
	if (icatGame.initializeWindow(1280, 720)) {
		initGame();
		do {
			// update game(deltaTime);
			icatGame.updateWindow();

		} while (!icatGame.ifWindowShouldClose());
		icatGame.terminate();
	}

	return 0;
}

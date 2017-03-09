#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
class Scene 
{
public:
	Scene();
	~Scene();

	void addEntity(Entity* entity);
	std::vector<Entity*>& getEntities();

private:
	std::vector<Entity*> entities;
};

#endif //SCENE_H
#include "scene.h"

int Scene::init(SDL_Renderer* renderer) {
  SDL_Log("scene init\n");
  r=renderer;
  nullEntity.x=200; nullEntity.y=200; nullEntity.r=renderer; nullEntity.speed=4; nullEntity.dir=20;
  // create one entity for now
  entities.resize(1);
  entities[0]=nullEntity;
  return 1;
}

void Scene::update() {
  for (std::vector<Entity>::iterator e=entities.begin(); e!=entities.end(); e++) {
    e->update();
  }
}

void Scene::draw() {
  for (std::vector<Entity>::iterator e=entities.begin(); e!=entities.end(); e++) {
    e->draw();
  }
}

Scene::Scene(string filename) {
  SDL_Log("done\n");
}
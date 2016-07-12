#include "scene.h"

int Scene::init(SDL_Renderer* renderer) {
  SDL_Log("scene init\n");
  r=renderer;
  nullEntity.x=200; nullEntity.y=200; nullEntity.r=renderer; nullEntity.mov.speed=4; nullEntity.mov.dir=20;
  // create one entity for now
  entities.resize(2);
  entities[0]=new testtype1;
  entities[0]->x=200;
  entities[0]->y=200;
  entities[0]->r=renderer;
  entities[0]->mov.speed=4;
  entities[0]->mov.dir=20;
  entities[1]=new Entity;
  entities[1]->x=200;
  entities[1]->y=300;
  entities[1]->r=renderer;
  entities[1]->mov.speed=3;
  entities[1]->mov.dir=45;
  return 1;
}

void Scene::update() {
  for (std::vector<Entity*>::iterator e=entities.begin(); e!=entities.end(); e++) {
    e[0]->update();
  }
}

void Scene::draw() {
  for (std::vector<Entity*>::iterator e=entities.begin(); e!=entities.end(); e++) {
    e[0]->draw();
  }
}

Scene::Scene(string filename) {
  SDL_Log("done\n");
}
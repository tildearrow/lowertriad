#ifndef SCENE_H
#define SCENE_H

#include "../lowertriad.h"
#include "../entity/entity.h"
#include "../entity/entities.h"

class Scene {
  std::vector<Entity*> entities;
  testtype1 nullEntity;
  unsigned char* data;
  SDL_Renderer* r;
  public:
    int init(SDL_Renderer* renderer);
    void update();
    void draw();
    int terminate();
    Scene(string filename);
};
#endif
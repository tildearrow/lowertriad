#ifndef SCENE_H
#define SCENE_H
#include "../lowertriad.h"
#include "../entity/entity.h"

class Scene {
  std::vector<Entity> entities;
  Entity nullEntity;
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
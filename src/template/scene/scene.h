#ifndef SCENE_H
#define SCENE_H
#include "../includes.h"
#include "../entity/entity.h"

class Scene {
  std::vector<Entity> entities;
  unsigned char* data;
  public:
    int init();
    void update();
    int terminate();
    Scene(string filename);
};
#endif
#ifndef ENTITY_H
#define ENTITY_H
#include "../lowertriad.h"

class Entity {
  public:
    SDL_Renderer* r;
    double x, y, speed, dir;
    void update();
    void draw();
};
#endif
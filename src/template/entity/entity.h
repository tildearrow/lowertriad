#ifndef ENTITY_H
#define ENTITY_H
#include "../includes.h"

class Entity {
  public:
    SDL_Renderer* r;
    double x, y;
    void update();
    void draw();
};
#endif
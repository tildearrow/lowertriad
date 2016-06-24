#ifndef ENTITY_H
#define ENTITY_H
#include "../lowertriad.h"

class Entity {
  public:
    SDL_Renderer* r;
    double x, y;
    LTEVector mov, grav;
    int timer[TIMERS_PER_ENTITY];
    void update();
    virtual void draw();
};
#endif
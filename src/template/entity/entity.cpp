#include "entity.h"

void Entity::update() {
  x+=decomposeVectorX(mov.speed,mov.dir);
  y-=decomposeVectorY(mov.speed,mov.dir);
}

void Entity::draw() {
  SDL_SetRenderDrawColor(r,255,255,255,255);
  SDL_RenderDrawPoint(r,x,y);
}
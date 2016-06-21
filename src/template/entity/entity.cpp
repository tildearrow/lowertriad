#include "entity.h"

void Entity::update() {
  x+=decomposeVectorX(mov.len,mov.dir);
  y-=decomposeVectorY(mov.len,mov.dir);
}

void Entity::draw() {
  SDL_SetRenderDrawColor(r,255,255,255,255);
  SDL_RenderDrawPoint(r,x,y);
}
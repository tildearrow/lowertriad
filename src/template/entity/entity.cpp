#include "entity.h"

void Entity::update() {

}

void Entity::draw() {
  SDL_SetRenderDrawColor(r,255,255,255,255);
  SDL_RenderDrawPoint(r,x,y);
}
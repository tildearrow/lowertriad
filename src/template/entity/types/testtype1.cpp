#include "testtype1.h"

void testtype1::draw() {
  SDL_SetRenderDrawColor(r,255,255,255,255);
  SDL_RenderDrawPoint(r,x,y);
  SDL_RenderDrawPoint(r,x+4,y);
  SDL_RenderDrawPoint(r,x,y+1);
}
#include "includes.h"
#include "engine.h"

LTGame* game;

int main(int argc, char** argv) {
  game=new LTGame;
  if (!game->init()) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"i'm sorry, but game can't init.\n");
    return 1;
  }
  game->doLoop();
  return 0;
}
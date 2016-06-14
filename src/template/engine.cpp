#include "engine.h"

void LTGame::init() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Log("%s initializing...\n",GAME_NAME);
}
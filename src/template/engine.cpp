#include "engine.h"

int LTGame::init() {
  ev=new SDL_Event;
  willquit=false;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Log("%s initializing...\n",GAME_NAME);
  SDL_Log("creating game window...\n");
  gamewindow=SDL_CreateWindow(GAME_NAME,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,480,0);
  gamer=SDL_CreateRenderer(gamewindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
  SDL_Log("initializing scenes...\n");
  scenes.resize(SCENE_COUNT);
  for (int i=0; i<SCENE_COUNT; i++) {
    scenes[i]=new Scene("scene.bin");
    if (!scenes[i]->init(gamer)) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"unable to init scene %d.\n",i);
      return 0;
    }
  }
  
  return 1;
}

void LTGame::doLoop() {
  SDL_Log("done. starting game.\n");
  while (1) {
    while (SDL_PollEvent(ev)) {
      switch (ev->type) {
	case SDL_QUIT:
	  willquit=true;
	  break;
      }
    }
    SDL_SetRenderDrawColor(gamer,0,0,0,0);
    SDL_RenderClear(gamer);
    scenes[0]->update();
    scenes[0]->draw();
    SDL_RenderPresent(gamer);
    if (willquit) {
      SDL_LogVerbose(SDL_LOG_CATEGORY_APPLICATION,"got quit event, but nobody handled it. quitting.\n");
      break;
    }
  }
  SDL_Log("game has finished successfully.\n");
}
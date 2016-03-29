#include "includes.h"
#include <unistd.h>
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Event* event;

int main() {
  // init everything
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    printf("i'm sorry, but SDL can't be loaded: %s\n",SDL_GetError());
    return 1;
  }
  string title;
  title="LowerTriad";
  mainWindow=SDL_CreateWindow(title.c_str(),0,0,1024,768,0);
  if (!mainWindow) {
    printf("i'm sorry, but window can't be created: %s\n",SDL_GetError());
    return 1;
  }
  mainRenderer=SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
  while (1) {
    SDL_RenderPresent(mainRenderer);
  }
  sleep(1);
  return 0;
}

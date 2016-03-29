#include "includes.h"
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Event* event;

int main() {
  // init everything
  SDL_Init(SDL_INIT_VIDEO);
  string title;
  title="LowerTriad";
  mainWindow=SDL_CreateWindow(title.c_str(),0,0,1024,600,0);
  if (!mainWindow) {
    printf("i'm sorry, but window can't be created: %s\n",SDL_GetError());
    return 1;
  }
  mainRenderer=SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
  while (1) {
    SDL_RenderClear(mainRenderer);
    SDL_RenderPresent(mainRenderer);
  }
  return 0;
}

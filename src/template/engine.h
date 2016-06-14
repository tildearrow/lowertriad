#include "includes.h"
#include "entity/entity.h"

class LTGame {
  std::queue<int> events;
  SDL_Window* gamewindow;
  SDL_Renderer* gamer;
  public:
    void init();
};

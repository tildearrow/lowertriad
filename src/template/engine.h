#include "lowertriad.h"
#include "entity/entity.h"
#include "scene/scene.h"

class LTGame {
  const char* sceneData[1]={
    "scene.bin"
  };
  std::queue<int> events;
  std::vector<Scene*> scenes;
  bool willquit;
  SDL_Event* ev;
  SDL_Window* gamewindow;
  SDL_Renderer* gamer;
  public:
    int init();
    void doLoop();
};

#include "includes.h"
#include "engine.h"

LTGame* game;

int main(int argc, char** argv) {
  game=new LTGame;
  game->init();
  return 0;
}
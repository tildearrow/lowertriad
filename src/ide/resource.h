#include "includes.h"

#ifndef RESOURCE_H
#define RESOURCE_H
struct ecode {
  int eventtype;
  string eventcode;
};

struct etype {
  string name;
  int id;
  int initialgraphic;
  int initialsubgraphic;
  int parent;
  int category;
  std::vector<ecode> eventcode;
  string headercode;
};

struct graphic {
  string name;
  int id;
  int width;
  int height;
  int originX, originY;
  int subgraphics;
  bool background;
  std::vector<unsigned char*> data;
  int colmode;
  unsigned char** colmask;
};

struct audio {
  string name;
  int id;
  int size;
  float* data;
  int finaltype;
};

struct viewport {
  SDL_Rect view, port;
  float viewangle, portangle;
};

struct scene {
  string name;
  int id;
  int width;
  int height;
  bool freeze;
  std::vector<viewport> viewports;
};

struct function {
  string name;
  int id;
  string code;
};
#endif
#include "includes.h"

class gfxeditor {
  unsigned char* data;
  int width;
  int height;
  int curtool;
  SDL_Color bg, fg;
  void drawcolorpicker();
  public:
    void draw();
    void mouse();
    void setdata(unsigned char* data, int width, int height);
};
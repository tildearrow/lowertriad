#include "includes.h"
#include "font.h"

class gfxeditor {
  unsigned char* data;
  int width;
  int height;
  int curtool;
  SDL_Color bg, fg;
  font* gf;
  void drawcolorpicker();
  public:
    void draw();
    void mouse();
    void setfont(font* fontset);
    void setdata(unsigned char* data, int width, int height);
};
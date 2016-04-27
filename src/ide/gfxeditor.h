#include "includes.h"
#include "font.h"

class gfxeditor {
  unsigned char* data;
  int width;
  int height;
  int curtool;
  SDL_Color bg, fg;
  SDL_Color color[16];
  SDL_Renderer* r;
  font* gf;
  void drawcolorpicker();
  public:
    int offX, offY;
    void draw();
    void mouse();
    void setfont(font* fontset);
    void setrenderer(SDL_Renderer* renderer);
    void setdata(unsigned char* data, int width, int height);
    void setcolor(int colindex, SDL_Color colcol);
};
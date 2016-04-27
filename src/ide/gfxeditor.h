#include "includes.h"
#include "font.h"

class gfxeditor {
  unsigned char* data;
  int width;
  int height;
  int curtool;
  SDL_Color bg, fg;
  SDL_Point temppoint;
  SDL_Rect temprect;
  SDL_Color color[16];
  SDL_Renderer* r;
  int* mX;
  int* mY;
  unsigned int* mB;
  unsigned int* mBold;
  font* gf;
  void drawcolorpicker();
  public:
    int offX, offY, w, h;
    void draw();
    void mouse();
    void setfont(font* fontset);
    void setrenderer(SDL_Renderer* renderer);
    void setdata(unsigned char* data, int width, int height);
    void setmouse(int* x, int* y, unsigned int* b, unsigned int* bold);
    void setcolor(int colindex, SDL_Color colcol);
    gfxeditor();
};
#include "includes.h"
#include "font.h"

class gfxeditor {
  std::vector<unsigned char*>* data;
  SDL_Texture* datadraw;
  int width;
  int height;
  int curtool;
  bool fgorbg;
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
    void setdata(std::vector<unsigned char*>* thedata, int thewidth, int theheight);
    void setmouse(int* x, int* y, unsigned int* b, unsigned int* bold);
    void setcolor(int colindex, SDL_Color colcol);
    gfxeditor();
};
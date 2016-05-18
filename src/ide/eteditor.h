#include "includes.h"
#include "resource.h"
#include "font.h"

class eteditor {
  etype* entitytype;
  font* f;
  SDL_Renderer* r;
  SDL_Color color[16];
  public:
    int offX, offY, w, h;
    void setetype(etype* e);
    void setfont(font* fontset);
    void setrenderer(SDL_Renderer* renderer);
    void setcolor(int colindex, SDL_Color colcol);
    void draw();
    eteditor();
};
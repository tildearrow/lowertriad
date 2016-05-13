#include "includes.h"
#include "resource.h"
#include "font.h"

class eteditor {
  etype* entitytype;
  font* f;
  SDL_Renderer* r;
  public:
    void setetype(etype* e);
    void setfont(font* fontset);
    void setrenderer(SDL_Renderer* renderer);
    void draw();
    eteditor();
};
#include "eteditor.h"

void eteditor::setetype(etype* e) {
  entitytype=e;
}

void eteditor::setfont(font* fontset) {
  f=fontset;
}

void eteditor::setrenderer(SDL_Renderer* renderer) {
  r=renderer;
}

void eteditor::draw() {
  f->drawf(256,256,{255,255,255,255},0,0,"%d",(entitytype==NULL));
  if (entitytype!=NULL) {
    f->draw(w-128, offY+2, color[0], 1, 0, false, "Events");
    SDL_RenderDrawLine(r, w, offY+20, w-256, offY+20);
    SDL_RenderDrawLine(r, w-256, offY, w-256, h);
  }
}

void eteditor::setcolor(int colindex, SDL_Color colcol) {
  color[colindex]=colcol;
}

eteditor::eteditor() {
  entitytype=NULL;
}
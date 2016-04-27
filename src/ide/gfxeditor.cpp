#include "gfxeditor.h"

void gfxeditor::draw() {
  SDL_SetRenderDrawColor(r,color[0].r,color[0].g,color[0].b,color[0].a);
  SDL_RenderDrawLine(r,offX,600-64,1024,600-64);
  //gf->draw(offX, offY, {255,255,255,255}, 0, 0, 0, "OH YES!");
}

void gfxeditor::drawcolorpicker() {
  
}

void gfxeditor::setdata(unsigned char* data, int width, int height) {
  
}

void gfxeditor::setfont(font* fontset) {
  gf=fontset;
}

void gfxeditor::setrenderer(SDL_Renderer* renderer) {
  r=renderer;
}

void gfxeditor::setcolor(int colindex, SDL_Color colcol) {
  color[colindex]=colcol;
}
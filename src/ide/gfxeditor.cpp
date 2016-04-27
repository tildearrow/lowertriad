#include "gfxeditor.h"

void gfxeditor::mouse() {
  if (*mB&1) {
    temppoint.x=*mX;
    temppoint.y=*mY;
    temprect.x=offX+24;
    temprect.y=h-55;
    temprect.w=256;
    temprect.h=10;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      fg.r=*mX-offX-24;
    }
    temprect.y=h-35;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      fg.g=*mX-offX-24;
    }
    temprect.y=h-15;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      fg.b=*mX-offX-24;
    }
  }
}

void gfxeditor::draw() {
  SDL_SetRenderDrawColor(r,color[0].r,color[0].g,color[0].b,color[0].a);
  SDL_RenderDrawLine(r,offX,h-64,w,h-64);
  gf->draw(offX+8,h-60,color[0],0,0,0,"R");
  gf->draw(offX+8,h-40,color[0],0,0,0,"G");
  gf->draw(offX+8,h-20,color[0],0,0,0,"B");
  // color sliders
  SDL_SetRenderDrawColor(r,color[0].r,color[0].g,color[0].b,color[0].a);
  temprect.x=offX+24;
  temprect.y=h-55;
  temprect.w=256;
  temprect.h=10;
  SDL_RenderDrawRect(r,&temprect);
  temprect.y=h-35;
  SDL_RenderDrawRect(r,&temprect);
  temprect.y=h-15;
  SDL_RenderDrawRect(r,&temprect);
  
  SDL_RenderDrawPoint(r,offX+24+fg.r,h-56);
  SDL_RenderDrawPoint(r,offX+24+fg.g,h-36);
  SDL_RenderDrawPoint(r,offX+24+fg.b,h-16);
  
  SDL_SetRenderDrawColor(r,fg.r,fg.g,fg.b,255);
  temprect.x=offX+288;
  temprect.y=h-58;
  temprect.w=54;
  temprect.h=54;
  SDL_RenderFillRect(r,&temprect);
  
  gf->drawf(offX+8,offY+8,color[0],0,0,"%d %d %d",*mX,*mY,*mB);
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

void gfxeditor::setmouse(int* x, int* y, unsigned int* b, unsigned int* bold) {
  mX=x; mY=y; mB=b; mBold=bold;
}

gfxeditor::gfxeditor() {
  bg.r=0; bg.g=0; bg.b=0; bg.a=255;
  fg.r=255; fg.g=255; fg.b=255; fg.a=255;
}
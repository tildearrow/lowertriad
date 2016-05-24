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

void eteditor::mouse() {
  if (*mB&1) {
    if (entitytype!=NULL) {
      temppoint.x=*mX;
      temppoint.y=*mY;
      temprect.x=w-256;
      temprect.y=offY+20;
      temprect.w=85;
      temprect.h=20;
      if (SDL_PointInRect(&temppoint,&temprect)) {
	select=true;
      }
    }
  }
}

void eteditor::draw() {
  f->drawf(256,256,{255,255,255,255},0,0,"%d",(entitytype==NULL));
  if (entitytype!=NULL) {
    f->draw(w-128, offY+2, color[0], 1, 0, false, "Events");
    SDL_RenderDrawLine(r, w, offY+20, w-256, offY+20);
    SDL_RenderDrawLine(r, w, offY+40, w-256, offY+40);
    SDL_RenderDrawLine(r, w-256, offY, w-256, h);
    
    SDL_RenderDrawLine(r, w-85, offY+20, w-85, offY+40);
    SDL_RenderDrawLine(r, w-171, offY+20, w-171, offY+40);
    
    f->draw(w-214, offY+22, color[0], 1, 0, 0, "Add");
    f->draw(w-128, offY+22, color[0], 1, 0, 0, "Change");
    f->draw(w-43, offY+22, color[0], 1, 0, 0, "Remove");
  }
}

void eteditor::eventselector() {
  
}

void eteditor::setcolor(int colindex, SDL_Color colcol) {
  color[colindex]=colcol;
}

void eteditor::setmouse(int* x, int* y, unsigned int* b, unsigned int* bold) {
  mX=x; mY=y; mB=b; mBold=bold;
}

eteditor::eteditor() {
  entitytype=NULL;
}
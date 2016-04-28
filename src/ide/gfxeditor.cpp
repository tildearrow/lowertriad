#include "gfxeditor.h"

void gfxeditor::mouse() {
  if (*mB&1) {
    temppoint.x=*mX;
    temppoint.y=*mY;
    temprect.x=offX+24;
    temprect.y=h-75;
    temprect.w=256;
    temprect.h=10;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      if (fgorbg) {
        bg.r=*mX-offX-24;
      } else {
        fg.r=*mX-offX-24;
      }
    }
    temprect.y=h-55;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      if (fgorbg) {
        bg.g=*mX-offX-24;
      } else {
        fg.g=*mX-offX-24;
      }
    }
    temprect.y=h-35;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      if (fgorbg) {
        bg.b=*mX-offX-24;
      } else {
        fg.b=*mX-offX-24;
      }
    }
    temprect.y=h-15;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      if (fgorbg) {
        bg.a=*mX-offX-24;
      } else {
        fg.a=*mX-offX-24;
      }
    }
    temprect.x=offX+288;
    temprect.y=h-80;
    temprect.w=25;
    temprect.h=20;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      fgorbg=false;
    }
    temprect.x=offX+288+29;
    if (SDL_PointInRect(&temppoint,&temprect)) {
      fgorbg=true;
    }
  }
}

void gfxeditor::draw() {
  SDL_SetRenderDrawColor(r,color[0].r,color[0].g,color[0].b,color[0].a);
  SDL_RenderDrawLine(r,offX,h-84,w,h-84);
  gf->draw(offX+8,h-80,color[0],0,0,0,"R");
  gf->draw(offX+8,h-60,color[0],0,0,0,"G");
  gf->draw(offX+8,h-40,color[0],0,0,0,"B");
  gf->draw(offX+8,h-20,color[0],0,0,0,"A");
  // color sliders
  SDL_SetRenderDrawColor(r,color[0].r,color[0].g,color[0].b,color[0].a);
  temprect.x=offX+24;
  temprect.y=h-75;
  temprect.w=256;
  temprect.h=10;
  SDL_RenderDrawRect(r,&temprect);
  temprect.y=h-55;
  SDL_RenderDrawRect(r,&temprect);
  temprect.y=h-35;
  SDL_RenderDrawRect(r,&temprect);
  temprect.y=h-15;
  SDL_RenderDrawRect(r,&temprect);
  
  temprect.x=offX+288;
  temprect.y=h-80;
  temprect.w=25;
  temprect.h=20;
  SDL_RenderDrawRect(r,&temprect);
  temprect.x=offX+288+29;
  SDL_RenderDrawRect(r,&temprect);
  
  gf->draw(offX+288+29+11,h-70,color[0],1,1,0,"B");
  gf->draw(offX+288+11,h-70,color[0],1,1,0,"F");
  
  if (fgorbg) {
    SDL_RenderDrawPoint(r,offX+24+bg.r,h-76);
    SDL_RenderDrawPoint(r,offX+24+bg.g,h-56);
    SDL_RenderDrawPoint(r,offX+24+bg.b,h-36);
    SDL_RenderDrawPoint(r,offX+24+bg.a,h-16);
  } else {
    SDL_RenderDrawPoint(r,offX+24+fg.r,h-76);
    SDL_RenderDrawPoint(r,offX+24+fg.g,h-56);
    SDL_RenderDrawPoint(r,offX+24+fg.b,h-36);
    SDL_RenderDrawPoint(r,offX+24+fg.a,h-16);
  }

  if (fgorbg) {
    SDL_SetRenderDrawColor(r,bg.r,bg.g,bg.b,255);
  } else {
    SDL_SetRenderDrawColor(r,fg.r,fg.g,fg.b,255);
  }
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
  fgorbg=0; // 0 is fg, 1 is bg
}
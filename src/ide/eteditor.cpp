/*
 * Copyright (c) 2016 tildearrow
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
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
    
    if (select) {
      eventselector();
    } else {
      codeeditor();
    }
  }
}

void eteditor::eventselector() {
  f->draw(offX,offY,color[0],1,0,0,"Event");
}

void eteditor::codeeditor() {
  f->draw(offX,offY,color[0],1,0,0,"Code Editor");
}

void eteditor::setcolor(int colindex, SDL_Color colcol) {
  color[colindex]=colcol;
}

void eteditor::setmouse(int* x, int* y, unsigned int* b, unsigned int* bold) {
  mX=x; mY=y; mB=b; mBold=bold;
}

eteditor::eteditor() {
  entitytype=NULL;
  select=false;
}
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
        selectedevent=0x00000000;
      }
      if (select) {
        temprect.w=(w-512)/5;
        temprect.h=20;
        temprect.y=offY+20;
        for (int i=0; i<5; i++) {
          temprect.x=offX+(((w-512)*i)/5);
          if (SDL_PointInRect(&temppoint,&temprect)) {
            switch (i) {
              case 0: selectedevent=0x00000000; break;
              case 1: selectedevent=0x01000000; break;
              case 2: selectedevent=0x02000000; break;
              case 3: selectedevent=0x03000000; break;
              case 4: selectedevent=0x0f000000; break;
            }
          }
        }
        temprect.y=offY+40;
        for (int i=0; i<5; i++) {
          temprect.x=offX+(((w-512)*i)/5);
          if (SDL_PointInRect(&temppoint,&temprect)) {
            switch (i) {
              case 0: selectedevent=0x10000000; break;
              case 1: selectedevent=0x20000000; break;
              case 2: selectedevent=0x70000000; break;
              case 3: selectedevent=0x7e000000; break;
              case 4: selectedevent=0x7f000000; break;
            }
          }
        }
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
  // header
  f->draw(w/2,offY,color[0],1,0,0,"Select Event");
  SDL_RenderDrawLine(r, offX, offY+20, w-256, offY+20);
  // event type buttons
  f->draw(offX+(int)(((float)w-512)*0.1),offY+20,color[((selectedevent>>24)==0x00)],1,0,0,"Entity");
  f->draw(offX+(int)(((float)w-512)*0.3),offY+20,color[((selectedevent>>24)==0x01)],1,0,0,"Frame");
  f->draw(offX+(int)(((float)w-512)*0.5),offY+20,color[((selectedevent>>24)==0x02)],1,0,0,"Collision");
  f->draw(offX+(int)(((float)w-512)*0.7),offY+20,color[((selectedevent>>24)==0x03)],1,0,0,"Timer");
  f->draw(offX+(int)(((float)w-512)*0.9),offY+20,color[((selectedevent>>24)==0x0f)],1,0,0,"Render");
  f->draw(offX+(int)(((float)w-512)*0.1),offY+40,color[((selectedevent>>28)==0x1)],1,0,0,"Input");
  f->draw(offX+(int)(((float)w-512)*0.3),offY+40,color[((selectedevent>>24)==0x20)],1,0,0,"Scene");
  f->draw(offX+(int)(((float)w-512)*0.5),offY+40,color[((selectedevent>>24)==0x70)],1,0,0,"Game");
  f->draw(offX+(int)(((float)w-512)*0.7),offY+40,color[((selectedevent>>24)==0x7e)],1,0,0,"Error");
  f->draw(offX+(int)(((float)w-512)*0.9),offY+40,color[((selectedevent>>24)==0x7f)],1,0,0,"User");
  SDL_RenderDrawLine(r, offX, offY+60, w-256, offY+60);
  // event-type-respective UI
  if ((selectedevent>>28)==0x1) {
    SDL_RenderDrawLine(r, offX, offY+80, w-256, offY+80);
    f->draw(offX+(int)(((float)w-512)*1/10),offY+60,color[((selectedevent>>24)==0x10)],1,0,0,"Keyboard");
    f->draw(offX+(int)(((float)w-512)*3/10),offY+60,color[((selectedevent>>24)==0x11)],1,0,0,"Mouse");
    f->draw(offX+(int)(((float)w-512)*5/10),offY+60,color[((selectedevent>>24)==0x12)],1,0,0,"Joystick");
    f->draw(offX+(int)(((float)w-512)*7/10),offY+60,color[((selectedevent>>24)==0x13)],1,0,0,"Touch");
    f->draw(offX+(int)(((float)w-512)*9/10),offY+60,color[((selectedevent>>24)==0x1f)],1,0,0,"Other");
  } else {
    switch (selectedevent>>24) {
      case 0:
        f->draw(w/2,offY+100,color[(selectedevent&0xf)==1],1,1,0,"Pre-Creation");
        f->draw(w/2,offY+160,color[(selectedevent&0xf)==2],1,1,0,"Creation");
        f->draw(w/2,offY+220,color[(selectedevent&0xf)==3],1,1,0,"Destruction");
        f->draw(w/2,offY+280,color[(selectedevent&0xf)==4],1,1,0,"Post-Destruction");
        break;
      case 1:
        f->draw(w/2,offY+100,color[(selectedevent&0xf)==1],1,1,0,"Pre-Frame");
        f->draw(w/2,offY+160,color[(selectedevent&0xf)==2],1,1,0,"Frame");
        f->draw(w/2,offY+220,color[(selectedevent&0xf)==3],1,1,0,"Post-Frame");
        break;
      case 2:
        SDL_RenderDrawLine(r, offX, offY+80, w-256, offY+80);
        f->draw(offX+(int)(((float)w-512)*1/6),offY+60,color[((selectedevent>>20)<0x02e)],1,0,0,"-> Entity Type");
        f->draw(offX+(int)(((float)w-512)*3/6),offY+60,color[((selectedevent>>20)==0x02e)],1,0,0,"-> Entity Group");
        f->draw(offX+(int)(((float)w-512)*5/6),offY+60,color[((selectedevent>>20)==0x02f)],1,0,0,"-> Other");
        break;
      case 3:
        SDL_RenderDrawLine(r, offX, offY+80, w-256, offY+80);
        f->draw(offX+(int)(((float)w-512)*1/4),offY+60,color[((selectedevent>>20)<0x038)],1,0,0,"Entity");
        f->draw(offX+(int)(((float)w-512)*3/4),offY+60,color[((selectedevent>>20)>0x037)],1,0,0,"Global");
        break;
      case 0x0f:
        f->draw(w/2,offY+100,color[(selectedevent&0xf)==1],1,1,0,"Pre-Clear");
        f->draw(w/2,offY+160,color[(selectedevent&0xf)==2],1,1,0,"Pre-Render");
        f->draw(w/2,offY+220,color[(selectedevent&0xf)==3],1,1,0,"Render");
        f->draw(w/2,offY+280,color[(selectedevent&0xf)==4],1,1,0,"Post-Render");
        f->draw(w/2,offY+340,color[(selectedevent&0xf)==4],1,1,0,"Overlay");
        f->draw(w/2,offY+400,color[(selectedevent&0xf)==4],1,1,0,"Post-Present");
        break;
      case 0x20:
        f->draw(w/2,offY+100,color[(selectedevent&0xf)==1],1,1,0,"Load");
        f->draw(w/2,offY+160,color[(selectedevent&0xf)==2],1,1,0,"Finish");
        break;
      case 0x70:
        f->draw(w/2,offY+100,color[(selectedevent&0xf)==1],1,1,0,"Start");
        f->draw(w/2,offY+160,color[(selectedevent&0xf)==2],1,1,0,"Exit");
        f->draw(w/2,offY+220,color[(selectedevent&0xf)==3],1,1,0,"Restart");
        f->draw(w/2,offY+280,color[(selectedevent&0xf)==4],1,1,0,"Close Button");
        break;
      case 0x7e:
        SDL_RenderDrawLine(r, offX, offY+80, w-256, offY+80);
        f->draw(offX+(int)(((float)w-512)*1/8),offY+60,color[(selectedevent==0x7e000000)],1,0,0,"Any Terminate");
        f->draw(offX+(int)(((float)w-512)*3/8),offY+60,color[(selectedevent==0x7e000001)],1,0,0,"Any Crash");
        f->draw(offX+(int)(((float)w-512)*5/8),offY+60,color[(selectedevent==0x7e000002)],1,0,0,"Any Signal");
        f->draw(offX+(int)(((float)w-512)*7/8),offY+60,color[((selectedevent>>20)==0x7e1)],1,0,0,"Specific Signal");
        break;
    }
  }
  // event ID
  SDL_RenderDrawLine(r, offX, h-20, w-256, h-20);
  f->drawf(offX+8,h-20,color[0],0,0,"Event ID: 0x%.8x",selectedevent);
  // done/cancel buttons
  SDL_RenderDrawLine(r,w-256-128,h-20,w-256-128,h);
  SDL_RenderDrawLine(r,w-256-64,h-20,w-256-64,h);
  f->draw(w-256-96,h-20,color[0],1,0,0,"Done");
  f->draw(w-256-32,h-20,color[0],1,0,0,"Cancel");

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
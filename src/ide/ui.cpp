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
#include "ui.h"

bool PIR(SDL_Rect r, int x, int y) {
  return (x>r.x && x<r.x+r.w && y>r.y && y<r.y+r.h);
}

void uisystem::drawall() {
  for (int i=0; i<buttons.size(); i++) {
    gf->draw(buttons[i].coords.x+buttons[i].coords.w/2, buttons[i].coords.y+buttons[i].coords.h/2, buttons[i].color, 1, 1, buttons[i].text);
    SDL_SetRenderDrawColor(renderer, buttons[i].color.r, buttons[i].color.g, buttons[i].color.b, buttons[i].color.a);
    if (PIR(buttons[i].coords, *mx, *my)) {
      SDL_RenderFillRect(renderer, &buttons[i].coords);
    } else {
      SDL_RenderDrawRect(renderer, &buttons[i].coords);
    }
  }
  for (int i=0; i<labels.size(); i++) {
    
  }
  for (int i=0; i<textfields.size(); i++) {
    
  }
}

void uisystem::setrenderer(SDL_Renderer* r) {
  renderer=r;
}

void uisystem::setmouse(int* x, int* y) {
  mx=x;
  my=y;
}

void uisystem::addbutton(int xpos, int ypos, int width, int height, string btext, string bhint, SDL_Color bcolor, SDL_Color bbordercolor) {
  buttons.resize(buttons.size()+1);
  buttons[buttons.size()-1].coords.x=xpos;
  buttons[buttons.size()-1].coords.y=ypos;
  buttons[buttons.size()-1].coords.w=width;
  buttons[buttons.size()-1].coords.h=height;
  buttons[buttons.size()-1].color.r=bcolor.r;
  buttons[buttons.size()-1].color.g=bcolor.g;
  buttons[buttons.size()-1].color.b=bcolor.b;
  buttons[buttons.size()-1].color.a=bcolor.a;
  buttons[buttons.size()-1].bordercolor.r=bbordercolor.r;
  buttons[buttons.size()-1].bordercolor.g=bbordercolor.g;
  buttons[buttons.size()-1].bordercolor.b=bbordercolor.b;
  buttons[buttons.size()-1].bordercolor.a=bbordercolor.a;
  buttons[buttons.size()-1].text=btext;
  buttons[buttons.size()-1].hint=bhint;
}

void uisystem::setfont(font* fontset) {
  gf=fontset;
}
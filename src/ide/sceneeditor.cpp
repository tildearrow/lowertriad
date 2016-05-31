/*
 * Copyright (c) 2016 tildearrow
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to duse, copy, modify, merge, publish, distribute, sublicense, and/or sell
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
#include "sceneeditor.h"

void sceneeditor::setscene(scene* s) {
  thescene=s;
}

void sceneeditor::setfont(font* fontset) {
  f=fontset;
}

void sceneeditor::setrenderer(SDL_Renderer* renderer) {
  r=renderer;
}

void sceneeditor::setcolor(int colindex, SDL_Color colcol) {
  color[colindex]=colcol;
}

void sceneeditor::setmouse(int* x, int* y, unsigned int* b, unsigned int* bold) {
  mX=x; mY=y; mB=b; mBold=bold;
}

void sceneeditor::draw() {
  f->drawf(256,256,{255,255,255,255},0,0,"%d",(thescene==NULL));
}

sceneeditor::sceneeditor() {
  thescene=NULL;
}
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
#include "font.h"

int font::load(const char* filename, int size) {
  f=TTF_OpenFont(filename, size);
  if (f==NULL) {return 0;} else {return 1;}
}

void font::setrenderer(SDL_Renderer* r) {
  renderer=r;
}

void font::drawf(int x, int y, SDL_Color col, int align, int valign, const char* format, ...) {
  
}

void font::draw(int x, int y, SDL_Color col, int align, int valign, bool nocache, string text) {
  temps=TTF_RenderUTF8_Blended(f, text.c_str(), col);
  if (temps==NULL) {printf("aaaa\n");}
  tempt=SDL_CreateTextureFromSurface(renderer, temps);
  tempr.x=x-((align==1)?(temps->clip_rect.w/2):(0));
  tempr.y=y-((valign==1)?(temps->clip_rect.h/2):(0));
  tempr.w=temps->clip_rect.w;
  tempr.h=temps->clip_rect.h;
  SDL_RenderCopy(renderer, tempt, &temps->clip_rect, &tempr);
  SDL_DestroyTexture(tempt);
  SDL_FreeSurface(temps);
}
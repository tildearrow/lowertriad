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
#ifndef FONT_H
#define FONT_H
#include "includes.h"

class font {
  TTF_Font* f;
  SDL_Renderer* renderer;
  SDL_Surface* temps;
  SDL_Texture* tempt;
  int* mx;
  int* my;
  char* formatcache;
  int curfsize;
  SDL_Rect tempr;
  public:
  void draw(int x, int y, SDL_Color col, int align, int valign, bool nocache, string text);
  void drawf(int x, int y, SDL_Color col, int align, int valign, const char* format, ...);
  int load(const char* filename, int size);
  void setrenderer(SDL_Renderer* r);
  void setcursor(int* mx, int* my);
};
#endif

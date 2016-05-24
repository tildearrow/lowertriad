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
#include "includes.h"

#ifndef RESOURCE_H
#define RESOURCE_H
struct ecode {
  int eventtype;
  string eventcode;
};

struct etype {
  string name;
  int id;
  int initialgraphic;
  int initialsubgraphic;
  int parent;
  int category;
  std::vector<ecode> eventcode;
  string headercode;
};

struct graphic {
  string name;
  int id;
  int width;
  int height;
  int originX, originY;
  int subgraphics;
  bool background;
  std::vector<unsigned char*> data;
  int colmode;
  unsigned char** colmask;
};

struct audio {
  string name;
  int id;
  int size;
  float* data;
  int finaltype;
};

struct viewport {
  SDL_Rect view, port;
  float viewangle, portangle;
};

struct scene {
  string name;
  int id;
  int width;
  int height;
  bool freeze;
  std::vector<viewport> viewports;
};

struct function {
  string name;
  int id;
  string code;
};
#endif
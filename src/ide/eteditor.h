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
#include "resource.h"
#include "font.h"

class eteditor {
  etype* entitytype;
  bool select;
  int selectedevent;
  int selevinlist;
  font* f;
  SDL_Renderer* r;
  SDL_Point temppoint;
  SDL_Rect temprect;
  SDL_Color color[16];
  int* mX;
  int* mY;
  unsigned int* mB;
  unsigned int* mBold;
  bool donotcreate;
  public:
    int offX, offY, w, h;
    void setetype(etype* e);
    void setfont(font* fontset);
    void setrenderer(SDL_Renderer* renderer);
    void setcolor(int colindex, SDL_Color colcol);
    void setmouse(int* x, int* y, unsigned int* b, unsigned int* bold);
    void mouse();
    void eventselector();
    void codeeditor();
    void draw();
    eteditor();
};
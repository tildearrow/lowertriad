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
#include "font.h"
#include "resource.h"
#include "../../lib/json/src/json.hpp"
typedef nlohmann::json json;

class fileopsform {
  string filename;
  font* f;
  SDL_Renderer* r;
  SDL_Point temppoint;
  SDL_Rect temprect;
  SDL_Color color[16];
  int* mX;
  int* mY;
  unsigned int* mB;
  unsigned int* mBold;
  std::vector<graphic>* graphics;
  std::vector<audio>* sounds;
  std::vector<etype>* etypes;
  std::vector<scene>* scenes;
  std::vector<function>* functions;
  int save(string dirname);
  int load(string dirname);
  public:
    int offX, offY, w, h;
    void setfont(font* fontset);
    void setrenderer(SDL_Renderer* renderer);
    void setcolor(int colindex, SDL_Color colcol);
    void setmouse(int* x, int* y, unsigned int* b, unsigned int* bold);
    void setdata(std::vector<graphic>* g, std::vector<audio>* s, std::vector<etype>* e, std::vector<scene>* sc, std::vector<function>* f);
    void mouse();
    void draw();
    fileopsform();
};
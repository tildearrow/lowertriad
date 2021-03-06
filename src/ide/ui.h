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

bool PIR(SDL_Rect* r, int x, int y);

struct button {
  SDL_Rect coords;
  string text, hint;
  SDL_Color color, bordercolor;
  void(* function)();
};

struct label {
  SDL_Rect coords;
  string text;
  SDL_Color color;
};

struct textfield {
  SDL_Rect coords;
  string text, hint, deftext;
  SDL_Color color, bordercolor, bgcolor;
};

class uisystem {
  std::vector<button> buttons;
  std::vector<label> labels;
  std::vector<textfield> textfields;
  SDL_Renderer* renderer;
  int* mx;
  int* my;
  unsigned int* mb;
  unsigned int* mbold;
  unsigned int mbpress;
  unsigned int mbrelease;
  font* gf;
public:
  void addbutton(int xpos, int ypos, int width, int height, string btext, string bhint, SDL_Color bcolor, SDL_Color bbordercolor, void(* function)());
  void setrenderer(SDL_Renderer* r);
  void setfont(font* fontset);
  void setmouse(int* x, int* y, unsigned int* b, unsigned int* bold);
  void drawall();
};
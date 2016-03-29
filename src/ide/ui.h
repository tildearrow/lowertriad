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

class uielement {
  public:
    SDL_Rect coords;
    SDL_Renderer* renderer;
};

class button:uielement {
  public:
    string text, hint;
    SDL_Color color, bordercolor;
  void draw();
};

class label:uielement {
  public:
    string text;
    SDL_Color color;
  void draw();
};

class textfield:uielement {
  public:
    string text, hint, deftext;
    SDL_Color color, bordercolor, bgcolor;
  void draw();
};

class uisystem {
  std::vector<button> buttons;
  std::vector<label> labels;
  std::vector<textfield> textfields;
  SDL_Renderer* renderer;
public:
  void addbutton(int x, int y, int w, int h, string text, string hint, SDL_Color color, SDL_Color bordercolor);
  void drawall();
};

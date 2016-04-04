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
#include "ui.h"
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Event* event;
int mouseX;
int mouseY;
SDL_Color color;
bool willquit;
uisystem* ui;
font* mainFont;

int main() {
  willquit=false;
  // init everything
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  ui=new uisystem;
  event=new SDL_Event;
  string title;
  title="LowerTriad";
  mainWindow=SDL_CreateWindow(title.c_str(),0,0,1024,600,SDL_WINDOW_RESIZABLE);
  if (!mainWindow) {
    printf("i'm sorry, but window can't be created: %s\n",SDL_GetError());
    return 1;
  }
  mainRenderer=SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
  // initialize UI
  mainFont=new font;
  mainFont->setrenderer(mainRenderer);
  if (!mainFont->load("/System/Library/Fonts/SFNSDisplay-Regular.otf",14)) {
    printf("can't load font\n");
  }
  ui->setrenderer(mainRenderer);
  color.r=255; color.g=255; color.b=255; color.a=255;
  ui->setfont(mainFont);
  ui->addbutton(16,16,64,32,"test","test hint",color,color);
  ui->setmouse(&mouseX,&mouseY);
  while (1) {
    // check events
    while (SDL_PollEvent(event)) {
      if (event->type==SDL_QUIT) {
        willquit=true;
      }
    }
    SDL_SetRenderDrawColor(mainRenderer,0,0,0,0);
    SDL_RenderClear(mainRenderer);
    SDL_GetMouseState(&mouseX, &mouseY);
    ui->drawall();
    SDL_RenderPresent(mainRenderer);
    if (willquit) {
      break;
    }
  }
  return 0;
}

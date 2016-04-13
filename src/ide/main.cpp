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
#ifdef _WIN32
#define FONT "C:\\Windows\\Fonts\\segoeui.ttf"
#elif __APPLE__
#define FONT "/System/Library/Fonts/SFNSDisplay-Regular.otf"
#elif __linux__
#define FONT "/usr/share/fonts/TTF/Ubuntu-R.ttf"
#else
#warning "really? please tell me if you are compiling on this OS"
#endif

#include "includes.h"
#include "font.h"
#include "ui.h"
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Event* event;
int mouseX;
int mouseY;
unsigned int mouseB;
unsigned int mouseBold;
SDL_Color color;
bool willquit;
uisystem* ui;
font* mainFont;
int curview;
int cureditid, curedittype;
const char* viewname[6]={"Graphics","Audio","Entity Types","Scenes","Functions"};

struct graphic {
  string name;
  int id;
  int width;
  int height;
  int originX, originY;
  int subgraphics;
  bool background;
  unsigned char** data;
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

struct etype {
  string name;
  int id;
  int initialgraphic;
  int initialsubgraphic;
  int parent;
  int category;
  std::vector<string> eventcode;
  string headercode;
};

struct viewport {
  SDL_Rect view, port;
  float viewangle, portangle;
};

struct scene {
  string name;
  int width;
  int height;
  bool freeze;
  std::vector<viewport> viewports;
};

struct function {
  string name;
  string code;
};

std::vector<graphic> graphics;
std::vector<audio> sounds;
std::vector<etype> etypes;
std::vector<scene> scenes;

void doNothing(){
  printf("hello world!\n");
}

void drawscreen() {
  SDL_RenderDrawLine(mainRenderer,0,32,1024,32);
  SDL_RenderDrawLine(mainRenderer,256,32,256,600);
  SDL_RenderDrawLine(mainRenderer,0,53,256,53);
  mainFont->drawf(128,41,color,1,1,"%s List",viewname[curview]);
  switch (curview) {
    case 0:
      for (int i=0; i<graphics.size(); i++) {
        mainFont->draw(0,64+(i*20),color,0,0,false,graphics[i].name);
      }
      break;
    case 1:
      for (int i=0; i<sounds.size(); i++) {
        mainFont->draw(0,64+(i*20),color,0,0,false,sounds[i].name);
      }
      break;
    case 2:
      for (int i=0; i<etypes.size(); i++) {
        mainFont->draw(0,64+(i*20),color,0,0,false,etypes[i].name);
      }
      break;
  }
}

void goGraphicsView() {
  curview=0;
}

void goAudioView() {
  curview=1;
}

void goETypesView() {
  curview=2;
}

void goScenesView() {
  curview=3;
}

void goFunctionsView() {
  curview=4;
}

void makeNewResource() {
  printf("ok, will be done\n");
  // make new resource
  int formersize;
  switch (curview) {
    case 0:
      formersize=graphics.size();
      graphics.resize(formersize+1);
      graphics[formersize].id=formersize;
      graphics[formersize].name="graphic";
      graphics[formersize].name+=std::to_string(formersize);
      break;
    case 1:
      formersize=sounds.size();
      sounds.resize(formersize+1);
      sounds[formersize].id=formersize;
      sounds[formersize].name="sound";
      sounds[formersize].name+=std::to_string(formersize);
      break;
    case 2:
      formersize=etypes.size();
      etypes.resize(formersize+1);
      etypes[formersize].id=formersize;
      etypes[formersize].name="type";
      etypes[formersize].name+=std::to_string(formersize);
      break;
  }
}

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
  if (!mainFont->load(FONT,14)) {
    printf("can't load font, which means this application is going to crash now...\n");
  }
  ui->setrenderer(mainRenderer);
  color.r=0; color.g=255; color.b=0; color.a=255;
  ui->setfont(mainFont);
  ui->addbutton(0,0,48,22,"Prepare","Prepare CMake project",color,color,doNothing);
  ui->addbutton(48,0,40,22,"Build","Build game",color,color,doNothing);
  ui->addbutton(100,0,32,22,"Run","Run compiled game",color,color,doNothing);
  ui->addbutton(132,0,56,22,"Package","Create package",color,color,doNothing);
  
  ui->addbutton(200,0,64,22,"Graphics","",color,color,goGraphicsView);
  ui->addbutton(264,0,50,22,"Audio","",color,color,goAudioView);
  ui->addbutton(314,0,80,22,"EntityTypes","",color,color,goETypesView);
  ui->addbutton(394,0,50,22,"Scenes","",color,color,goScenesView);
  ui->addbutton(444,0,72,22,"Functions","",color,color,goFunctionsView);
  ui->addbutton(225,32,32,22,"Add","",color,color,makeNewResource);
  
  ui->setmouse(&mouseX,&mouseY,&mouseB,&mouseBold);
  // initialize IDE variables
  cureditid=-1; curedittype=0; curview=0;
  while (1) {
    // check events
    while (SDL_PollEvent(event)) {
      if (event->type==SDL_QUIT) {
        willquit=true;
      }
    }
    SDL_SetRenderDrawColor(mainRenderer,0,0,0,0);
    SDL_RenderClear(mainRenderer);
    mouseBold=mouseB;
    mouseB=SDL_GetMouseState(&mouseX, &mouseY);
    ui->drawall();
    drawscreen();
    SDL_RenderPresent(mainRenderer);
    if (willquit) {
      break;
    }
  }
  return 0;
}

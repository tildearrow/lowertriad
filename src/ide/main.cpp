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
#include "gfxeditor.h"
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Event* event;
int mouseX;
int mouseY;
unsigned int mouseB;
unsigned int mouseBold;
SDL_Color color[16];
bool willquit;
uisystem* ui;
gfxeditor* geditor;
font* mainFont;
int curview;
int cureditid, curedittype;
const char* viewname[9]={"Graphics","Audio","Entity Types","Scenes","Functions","ShouldNotAppear","ShouldNotAppear","ShouldNotAppear","ShouldNotAppear"};

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

std::vector<graphic> graphics;
std::vector<audio> sounds;
std::vector<etype> etypes;
std::vector<scene> scenes;
std::vector<function> functions;

void doNothing(){
  printf("hello world!\n");
}

void drawScreen() {
  SDL_RenderDrawLine(mainRenderer,0,32,1024,32);
  if (curview<5) {
    SDL_RenderDrawLine(mainRenderer,256,32,256,600);
    SDL_RenderDrawLine(mainRenderer,0,53,256,53);
    mainFont->drawf(128,41,color[0],1,1,"%s List",viewname[curview]);
    switch (curview) {
      case 0:
        for (int i=0; i<graphics.size(); i++) {
          mainFont->draw(0,64+(i*20),((cureditid==i && curedittype==0)?(color[1]):(color[0])),0,0,false,graphics[i].name);
        }
        // also draw graphic editor
        geditor->draw();
        break;
      case 1:
        for (int i=0; i<sounds.size(); i++) {
          mainFont->draw(0,64+(i*20),((cureditid==i && curedittype==1)?(color[1]):(color[0])),0,0,false,sounds[i].name);
        }
        break;
      case 2:
        for (int i=0; i<etypes.size(); i++) {
          mainFont->draw(0,64+(i*20),((cureditid==i && curedittype==2)?(color[1]):(color[0])),0,0,false,etypes[i].name);
        }
        break;
      case 3:
        for (int i=0; i<scenes.size(); i++) {
          mainFont->draw(0,64+(i*20),((cureditid==i && curedittype==3)?(color[1]):(color[0])),0,0,false,scenes[i].name);
        }
        break;
      case 4:
        for (int i=0; i<functions.size(); i++) {
          mainFont->draw(0,64+(i*20),((cureditid==i && curedittype==4)?(color[1]):(color[0])),0,0,false, functions[i].name);
        }
        break;
    }
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

void goProjectView() {
  curview=5;
}

void goSettingsView() {
  curview=6;
}

void goHelpView() {
  curview=7;
}

void goAboutView() {
  curview=8;
}

void handleMouse() {
  if ((mouseB&1)>(mouseBold&1)) { // checks for mouse left pressed
    if (mouseX<256 && mouseY>64) {
      curedittype=curview;
      cureditid=(mouseY-64)/20;
      switch (curview) {
        case 0:
	  if (cureditid>=graphics.size()) {
	    cureditid=-1;
	  }
	  if (cureditid!=-1) {
	    geditor->setdata(graphics[cureditid].data[0], graphics[cureditid].width, graphics[cureditid].height);
	  }
	  break;
	case 1:
	  if (cureditid>=sounds.size()) {
	    cureditid=-1;
	  }
	  break;
	case 2:
	  if (cureditid>=etypes.size()) {
	    cureditid=-1;
	  }
	  break;
	case 3:
	  if (cureditid>=scenes.size()) {
	    cureditid=-1;
	  }
	  break;
	case 4:
	  if (cureditid>=functions.size()) {
	    cureditid=-1;
	  }
	  break;
      }
    }
  }
}

void makeNewResource() {
  // make new resource
  int formersize;
  switch (curview) {
    case 0:
      formersize=graphics.size();
      graphics.resize(formersize+1);
      graphics[formersize].id=formersize;
      graphics[formersize].name="graphic";
      graphics[formersize].name+=std::to_string(formersize);
      // create pre-defined graphic
      graphics[formersize].subgraphics=1;
      graphics[formersize].width=32;
      graphics[formersize].height=32;
      graphics[formersize].data.resize(1);
      graphics[formersize].data[0]=new unsigned char[4096];
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
    case 3:
      formersize=scenes.size();
      scenes.resize(formersize+1);
      scenes[formersize].id=formersize;
      scenes[formersize].name="scene";
      scenes[formersize].name+=std::to_string(formersize);
      break;
    case 4:
      formersize=functions.size();
      functions.resize(formersize+1);
      functions[formersize].id=formersize;
      functions[formersize].name="func";
      functions[formersize].name+=std::to_string(formersize);
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
  color[0].r=192; color[0].g=192; color[0].b=192; color[0].a=255; // main
  color[1].r=255; color[1].g=255; color[1].b=255; color[1].a=255; // alternate
  color[2].r=0;   color[2].g=255; color[2].b=0;   color[2].a=255; // success
  color[3].r=255; color[3].g=255; color[3].b=0;   color[3].a=255; // ongoing
  color[4].r=255; color[4].g=0;   color[4].b=0;   color[4].a=255; // failure
  ui->setfont(mainFont);
  ui->addbutton(0,0,48,22,"Prepare","Prepare CMake project",color[0],color[0],doNothing);
  ui->addbutton(48,0,40,22,"Build","Build game",color[0],color[0],doNothing);
  ui->addbutton(100,0,32,22,"Run","Run compiled game",color[0],color[0],doNothing);
  ui->addbutton(132,0,56,22,"Package","Create package",color[0],color[0],doNothing);
  
  ui->addbutton(200,0,64,22,"Graphics","",color[0],color[0],goGraphicsView);
  ui->addbutton(264,0,50,22,"Audio","Sound/Music",color[0],color[0],goAudioView);
  ui->addbutton(314,0,80,22,"EntityTypes","",color[0],color[0],goETypesView);
  ui->addbutton(394,0,50,22,"Scenes","",color[0],color[0],goScenesView);
  ui->addbutton(444,0,72,22,"Functions","",color[0],color[0],goFunctionsView);
  ui->addbutton(516,0,60,22,"Project","",color[0],color[0],goProjectView);
  
  ui->addbutton(1024-160,0,60,22,"Settings","",color[0],color[0],goSettingsView);
  ui->addbutton(1024-100,0,50,22,"Help","",color[0],color[0],goHelpView);
  ui->addbutton(1024-50,0,50,22,"About","",color[0],color[0],goAboutView);
  
  ui->addbutton(225,32,32,22,"Add","Add a new resource",color[0],color[0],makeNewResource);
  
  ui->setmouse(&mouseX,&mouseY,&mouseB,&mouseBold);
  // initialize graphic editor
  geditor=new gfxeditor;
  geditor->setfont(mainFont);
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
    SDL_SetRenderDrawColor(mainRenderer,color[0].r,color[0].g,color[0].b,color[0].a);
    mouseBold=mouseB;
    mouseB=SDL_GetMouseState(&mouseX, &mouseY);
    handleMouse();
    drawScreen();
    ui->drawall();
    SDL_RenderPresent(mainRenderer);
    if (willquit) {
      break;
    }
  }
  return 0;
}

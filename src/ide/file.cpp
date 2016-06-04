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
#include "file.h"

int fileopsform::save(string dirname) {
  printf("SHALL SAVE\n");
  time_t curtime;
  curtime=time(NULL);
  // begin saving
  // this is entirely experimental code for now
  // check for directory
  // sorry, no windows support.
  struct stat tempstat;
  if (stat(dirname.c_str(),&tempstat)==-1) {
    if (errno==2) {
      printf("dir does not exist. creating.\n");
      mkdir(dirname.c_str(),0755);
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (S_ISDIR(tempstat.st_mode)) {
      printf("project exists. overwriting.\n");
    } else {
      printf("is not a directory. sorry.\n");
      return false;
    }
  }
  // begin writing the project
  FILE* ff;
  string curfilename;
  // projectname.json
  curfilename=dirname+DS+dirname+".json";
  ff=fopen(curfilename.c_str(),"wb");
  fprintf(ff,"{\n\
  \"projectName\": \"%s\",\n\
  \"projectID\": \"00000000-0000-0000-0000-000000000000\",\n\
  \"lastSaveVersionType\": %d,\n\
  \"lastSaveVersion\": \"null\",\n\
  \"formatVersion\": %d,\n\
  \"saveTime\": %ld\n\
}",dirname.c_str(),vertype,formatver,curtime);
  fclose(ff);
  // ResourceIndex.json
  curfilename=dirname+DS+"ResourceIndex.json";
  ff=fopen(curfilename.c_str(),"wb");
  
  fprintf(ff,"{\n\
  \"graphicsDirectory\": \"Graphic\",\n\
  \"graphics\": [\n");
  for (int i=0; i<graphics->size(); i++) {
    fprintf(ff,"    \"%s.json\"",graphics[0][i].name.c_str());
    if (i==graphics->size()-1) {
      fprintf(ff,"\n");
    } else {
      fprintf(ff,",\n");
    }
  }
  fprintf(ff,"  ],\n");
  
  fprintf(ff,"\
  \"audioDirectory\": \"Audio\",\n\
  \"audio\": [\n");
  for (int i=0; i<sounds->size(); i++) {
    fprintf(ff,"    \"%s.json\"",sounds[0][i].name.c_str());
    if (i==sounds->size()-1) {
      fprintf(ff,"\n");
    } else {
      fprintf(ff,",\n");
    }
  }
  fprintf(ff,"  ],\n");
  
  fprintf(ff,"\
  \"entityTypesDirectory\": \"EntityType\",\n\
  \"entityTypes\": [\n");
  for (int i=0; i<etypes->size(); i++) {
    fprintf(ff,"    \"%s.json\"",etypes[0][i].name.c_str());
    if (i==etypes->size()-1) {
      fprintf(ff,"\n");
    } else {
      fprintf(ff,",\n");
    }
  }
  fprintf(ff,"  ],\n");
  
  fprintf(ff,"\
  \"scenes\": \"Scene\",\n\
  \"scenes\": [\n");
  for (int i=0; i<scenes->size(); i++) {
    fprintf(ff,"    \"%s.json\"",scenes[0][i].name.c_str());
    if (i==scenes->size()-1) {
      fprintf(ff,"\n");
    } else {
      fprintf(ff,",\n");
    }
  }
  fprintf(ff,"  ],\n");
  
  fprintf(ff,"\
  \"functionsDirectory\": \"Function\",\n\
  \"functions\": [\n");
  for (int i=0; i<functions->size(); i++) {
    fprintf(ff,"    \"%s.json\"",functions[0][i].name.c_str());
    if (i==functions->size()-1) {
      fprintf(ff,"\n");
    } else {
      fprintf(ff,",\n");
    }
  }
  fprintf(ff,"  ]\n\
}");
  
  fclose(ff);
  // Graphic, Audio, EntityType, Scene and Function directories
  curfilename=dirname+DS+"Graphic";
  if (stat(curfilename.c_str(),&tempstat)==-1) {
    if (errno==2) {
      printf("creating Graphic dir...\n");
      mkdir(curfilename.c_str(),0755);
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (S_ISDIR(tempstat.st_mode)) {
      printf("Graphic dir exists\n");
    } else {
      printf("Graphic is not a directory. sorry.\n");
      return false;
    }
  }
  
  curfilename=dirname+DS+"Audio";
  if (stat(curfilename.c_str(),&tempstat)==-1) {
    if (errno==2) {
      printf("creating Audio dir...\n");
      mkdir(curfilename.c_str(),0755);
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (S_ISDIR(tempstat.st_mode)) {
      printf("Audio dir exists\n");
    } else {
      printf("Audio is not a directory. sorry.\n");
      return false;
    }
  }
  
  curfilename=dirname+DS+"EntityType";
  if (stat(curfilename.c_str(),&tempstat)==-1) {
    if (errno==2) {
      printf("creating EntityType dir...\n");
      mkdir(curfilename.c_str(),0755);
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (S_ISDIR(tempstat.st_mode)) {
      printf("EntityType dir exists\n");
    } else {
      printf("EntityType is not a directory. sorry.\n");
      return false;
    }
  }
  
  curfilename=dirname+DS+"Scene";
  if (stat(curfilename.c_str(),&tempstat)==-1) {
    if (errno==2) {
      printf("creating Scene dir...\n");
      mkdir(curfilename.c_str(),0755);
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (S_ISDIR(tempstat.st_mode)) {
      printf("Scene dir exists\n");
    } else {
      printf("Scene is not a directory. sorry.\n");
      return false;
    }
  }
  
  curfilename=dirname+DS+"Function";
  if (stat(curfilename.c_str(),&tempstat)==-1) {
    if (errno==2) {
      printf("creating Function dir...\n");
      mkdir(curfilename.c_str(),0755);
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (S_ISDIR(tempstat.st_mode)) {
      printf("Function dir exists\n");
    } else {
      printf("Function is not a directory. sorry.\n");
      return false;
    }
  }
  
  // GraphicResourceName.json
  
  for (int i=0; i<graphics->size(); i++) {
    curfilename=dirname+DS+"Graphic"+DS+graphics[0][i].name+".json";
    ff=fopen(curfilename.c_str(),"wb");
    fprintf(ff,"{\n\
  \"resourceName\": \"%s\",\n\
  \"width\": %d,\n\
  \"height\": %d,\n\
  \"frames\": %d,\n\
  \"isBackground\": 0,\n\
  \"colMask\": {\n\
    \"type\": 0,\n\
    \"colMaskCoords\": {\n\
      \"x\": 0,\n\
      \"y\": 0,\n\
      \"w\": %d,\n\
      \"h\": %d\n\
    },\n\
    \"threshold\": 0,\n\
    \"multipleColMask\": 0,\n\
    \"colMaskFile\": \"Data/null.bin\"\n\
  },\n\
  \"origin\": {\n\
    \"x\": %d,\n\
    \"y\": %d\n\
  },\n\
  \"graphicFile\": \"Data/null.png\"\n\
}",graphics[0][i].name.c_str(), graphics[0][i].width, graphics[0][i].height,
   graphics[0][i].subgraphics, graphics[0][i].width, graphics[0][i].height,
   graphics[0][i].originX, graphics[0][i].originY);

    fclose(ff);
  }
  
  printf("success\n");
  return true;
}

void fileopsform::setfont(font* fontset) {
  f=fontset;
}

void fileopsform::setrenderer(SDL_Renderer* renderer) {
  r=renderer;
}

void fileopsform::setcolor(int colindex, SDL_Color colcol) {
  color[colindex]=colcol;
}

void fileopsform::setmouse(int* x, int* y, unsigned int* b, unsigned int* bold) {
  mX=x; mY=y; mB=b; mBold=bold;
}

void fileopsform::mouse() {
  if ((((*mB)^(*mBold))&(*mB))==1) {
    temppoint.x=*mX;
    temppoint.y=*mY;
    if (temppoint.y>offY) {
      // for now. when the save code is stable, this will be something else.
      int state;
      state=save("savedproject");
    }
  }
}

void fileopsform::draw() {
  f->drawf(256,256,{255,255,255,255},0,0,"click to save to savedproject/. you will be able to change path later.");
}

void fileopsform::setdata(std::vector<graphic>* g, std::vector<audio>* s, std::vector<etype>* e, std::vector<scene>* sc, std::vector<function>* f) {
  graphics=g;
  sounds=s;
  etypes=e;
  scenes=sc;
  functions=f;
}

fileopsform::fileopsform() {

}
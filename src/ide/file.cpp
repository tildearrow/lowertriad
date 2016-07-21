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
  struct stat tempstat;
  if (stat(dirname.c_str(),&tempstat)==-1) {
    if (errno==2) {
      printf("dir does not exist. creating.\n");
      #ifdef _WIN32
      CreateDirectory(dirname.c_str(),NULL);
      #else
      mkdir(dirname.c_str(),0755);
      #endif
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (tempstat.st_mode&0040000) {
      printf("project exists. overwriting.\n");
    } else {
      printf("is not a directory. sorry.\n");
      return false;
    }
  }
  // begin writing the project
  FILE* ff;
  string curfilename, projd;
  json proj;
  std::vector<string> names;
  // projectname.json
  curfilename=dirname+DS+"Project.json";
  ff=fopen(curfilename.c_str(),"wb");
  proj={
    {"projectName", dirname},
    {"projectID","00000000-0000-0000-0000-000000000000"},
    {"lastSaveVersionType",vertype},
    {"lastSaveVersion","null"},
    {"formatVersion",formatver},
    {"saveTime",curtime}
  };
  projd=proj.dump(2);
  fprintf(ff,projd.c_str());
  fclose(ff);
  // ResourceIndex.json
  curfilename=dirname+DS+"ResourceIndex.json";
  ff=fopen(curfilename.c_str(),"wb");
  
  proj.clear();
  proj["graphicsDirectory"]="Graphic";
  proj["audioDirectory"]="Audio";
  proj["entityTypesDirectory"]="EntityType";
  proj["scenesDirectory"]="Scene";
  proj["functionsDirectory"]="Function";
  
  names.resize(0);
  for (int i=0; i<graphics->size(); i++) {
    names.push_back(graphics[0][i].name);
  }
  proj["graphics"]=names;
  
  names.resize(0);
  for (int i=0; i<sounds->size(); i++) {
    names.push_back(sounds[0][i].name);
  }
  proj["audio"]=names;
  
  names.resize(0);
  for (int i=0; i<etypes->size(); i++) {
    names.push_back(etypes[0][i].name);
  }
  proj["entityTypes"]=names;
  
  names.resize(0);
  for (int i=0; i<scenes->size(); i++) {
    names.push_back(scenes[0][i].name);
  }
  proj["scenes"]=names;
  
  names.resize(0);
  for (int i=0; i<functions->size(); i++) {
    names.push_back(functions[0][i].name);
  }
  proj["functions"]=names;
  
  projd=proj.dump(2);
  fprintf(ff,projd.c_str());
  fclose(ff);
  // Graphic, Audio, EntityType, Scene and Function directories
  curfilename=dirname+DS+"Graphic";
  if (stat(curfilename.c_str(),&tempstat)==-1) {
    if (errno==2) {
      printf("creating Graphic dir...\n");
      #ifdef _WIN32
      CreateDirectory(curfilename.c_str(), NULL);
      #else
      mkdir(curfilename.c_str(), 0755);
      #endif
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (tempstat.st_mode&0040000) {
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
      #ifdef _WIN32
      CreateDirectory(curfilename.c_str(), NULL);
      #else
      mkdir(curfilename.c_str(), 0755);
      #endif
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (tempstat.st_mode&0040000) {
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
      #ifdef _WIN32
      CreateDirectory(curfilename.c_str(), NULL);
      #else
      mkdir(curfilename.c_str(), 0755);
      #endif
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (tempstat.st_mode&0040000) {
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
      #ifdef _WIN32
      CreateDirectory(curfilename.c_str(), NULL);
      #else
      mkdir(curfilename.c_str(), 0755);
      #endif
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (tempstat.st_mode&0040000) {
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
      #ifdef _WIN32
      CreateDirectory(curfilename.c_str(), NULL);
      #else
      mkdir(curfilename.c_str(), 0755);
      #endif
    } else {
      perror("i'm sorry, but");
      return false;
    }
  } else {
    if (tempstat.st_mode&0040000) {
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
    
    proj.clear();
    
    proj={
      {"resourceName",graphics[0][i].name},
      {"width",graphics[0][i].width},
      {"height",graphics[0][i].height},
      {"frames",graphics[0][i].subgraphics},
      {"isBackground",graphics[0][i].background},
      {"colMask",{
	  {"type",0},
	  {"colMaskCoords",{
	      {"x",0},
	      {"y",0},
	      {"w",graphics[0][i].width},
	      {"h",graphics[0][i].height},
	    }
	  },
	  {"threshold",0},
	  {"multipleColMask",0},
	  {"colMaskFile","Data/null.bin"}
	}
      },
      {"origin",{
	  {"x",graphics[0][i].originX},
	  {"y",graphics[0][i].originY}
	}
      },
      {"graphicFile","Data/null.png"}
    };

    projd=proj.dump(2);
    fprintf(ff,projd.c_str());
    fclose(ff);
  }
  
  // ETypeName.json
  
  for (int i=0; i<etypes->size(); i++) {
    curfilename=dirname+DS+"EntityType"+DS+etypes[0][i].name+".json";
    ff=fopen(curfilename.c_str(),"wb");
    
    proj.clear();
    
    proj={
      {"resourceName",etypes[0][i].name},
      {"defaultGraphic",etypes[0][i].initialgraphic},
      {"defaultSubGraphic",etypes[0][i].initialsubgraphic},
      {"parent",etypes[0][i].parent},
      {"category",etypes[0][i].category}
    };
    
    for (int j=0; j<etypes[0][i].eventcode.size(); j++) {
      char* r;
      // aaaaaaaaaaaaaaaaaaargh!!!!
      #ifdef _WIN32
      // for now. until i get visual studio on this 16GB thing.
      snprintf(r,2047,"Code/%s/Event%.8X.cpp",etypes[0][i].name.c_str(),etypes[0][i].eventcode[j].eventtype);
      #else
      asprintf(&r,"Code/%s/Event%.8X.cpp",etypes[0][i].name.c_str(),etypes[0][i].eventcode[j].eventtype);
      #endif
      proj["events"]+={
	{"id",etypes[0][i].eventcode[j].eventtype},
	{"code",r}
      };
      free(r);
    }
    
    projd=proj.dump(2);
    fprintf(ff,projd.c_str());
    fclose(ff);
  }
  
  // SceneName.json
  
  for (int i=0; i<scenes->size(); i++) {
    curfilename=dirname+DS+"Scene"+DS+scenes[0][i].name+".json";
    ff=fopen(curfilename.c_str(),"wb");
    
    proj.clear();
    
    proj={
      {"resourceName",scenes[0][i].name},
      {"width",scenes[0][i].width},
      {"height",scenes[0][i].height},
      {"grid",{
	  {"width",scenes[0][i].grid.w},
	  {"height",scenes[0][i].grid.h},
	  {"angle",scenes[0][i].grid.a}
	}
      },
      {"initCode","null"},
      {"finishCode","null"},
      {"freeze",scenes[0][i].freeze},
      {"clearColor",(scenes[0][i].clearcolor.r)<<24+
		    (scenes[0][i].clearcolor.g)<<16+
		    (scenes[0][i].clearcolor.b)<<8+
		    (scenes[0][i].clearcolor.a)
      }
    };
    
    for (int j=0; j<scenes[0][i].backgrounds.size(); j++) {
      proj["backgrounds"]+={
	
      };
    }
    
    for (int j=0; j<scenes[0][i].viewports.size(); j++) {
      proj["viewports"]+={
	
      };
    }
    
    for (int j=0; j<scenes[0][i].layers.size(); j++) {
      proj["layers"]+={
	
      };
    }
    
    projd=proj.dump(2);
    fprintf(ff,projd.c_str());
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

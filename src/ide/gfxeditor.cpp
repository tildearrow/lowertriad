#include "gfxeditor.h"

void gfxeditor::draw() {
  gf->draw(256, 256, {255,255,255,255}, 0, 0, 0, "OH YES!");
}

void gfxeditor::drawcolorpicker() {
  
}

void gfxeditor::setdata(unsigned char* data, int width, int height) {
  
}

void gfxeditor::setfont(font* fontset) {
  gf=fontset;
}
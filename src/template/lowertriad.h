#include "includes.h"

class LTRectangle {
  public:
    double x, y, w, h;
    double area();
    double angle();
};

struct LTPoint {
  double x, y;
};

struct LTColor {
  double r, g, b, a;
};

LTRectangle makeRectangleFromPoints(LTPoint p1, LTPoint p2);
LTRectangle makeRectangleLength(double x, double y, double w, double h);
LTRectangle makeRectangle(double x1, double y1, double x2, double y2);
double pointDistance(LTPoint p1, LTPoint p2);
double pointDirection(LTPoint p1, LTPoint p2);
LTColor makeColorFromRGB(unsigned char r, unsigned char g, unsigned char b);
LTColor makeColorFromRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
LTColor makeColorFromDoubleRGB(double r, double g, double b);
LTColor makeColorFromDoubleRGBA(double r, double g, double b, double a);
LTColor makeColorFromSDLColor(SDL_Color color);
void setBlendMode(int mode);

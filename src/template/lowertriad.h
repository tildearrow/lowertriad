#ifndef INCLUDES_H
#define INCLUDES_H
#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <queue>
#include <vector>

typedef std::string string;

#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define GAME_NAME "lowertriad"
#define SCENE_COUNT 1
#define TIMERS_PER_ENTITY 16

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

struct LTMovement {
  double speed, dir;
};

LTRectangle makeRectangleFromPoints(LTPoint p1, LTPoint p2);
LTRectangle makeRectangleLength(double x, double y, double w, double h);
LTRectangle makeRectangle(double x1, double y1, double x2, double y2);
double pointDistance(LTPoint p1, LTPoint p2);
double pointDirection(LTPoint p1, LTPoint p2);
double decomposeVectorX(double len, double dir);
double decomposeVectorY(double len, double dir);
LTColor makeColorFromRGB(unsigned char r, unsigned char g, unsigned char b);
LTColor makeColorFromRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
LTColor makeColorFromDoubleRGB(double r, double g, double b);
LTColor makeColorFromDoubleRGBA(double r, double g, double b, double a);
LTColor makeColorFromSDLColor(SDL_Color color);
void setBlendMode(int mode);
#endif

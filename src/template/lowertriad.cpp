#include "lowertriad.h"

double decomposeVectorX(double len, double dir) {
  return cos(dir*pi/180)*len;
}

double decomposeVectorY(double len, double dir) {
  return sin(dir*pi/180)*len;
}
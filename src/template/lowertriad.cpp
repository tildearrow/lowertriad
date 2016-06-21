#include "lowertriad.h"

double decomposeVectorX(double mod, double dir) {
  return cos(dir*pi/180)*mod;
}

double decomposeVectorY(double mod, double dir) {
  return sin(dir*pi/180)*mod;
}
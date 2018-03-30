#include <math.h>
#include <stdio.h>

#include "complex.h"

Complex newCpx(double re , double im) {
  Complex c = {re, im};
  return c;
}

Complex pow2Cpx(Complex* value) {
  double re = value->re * value->re - value->im * value->im;
  double im = 2 * value->re * value->im;
  Complex square = {re, im};
  return square;
}

Complex addCpx(Complex* first , Complex* second) {
  double re = first->re + second->re;
  double im = first->im + second->im;
  Complex cpx = {re , im};
  return cpx;
}

double modCpx(Complex* value) {
  double t = value->re * value->re + value->im * value->im;
  return sqrt(t);
}

void parseCpx(char* str , Complex* targetCpx) {
  double re;
  double im;
  int parseRes = sscanf(str , "%lf%lf", &re , &im);
  if(parseRes == 2) {
    targetCpx->re = re;
    targetCpx->im = im;
  }
}


Boundaries getBoundaries(Complex* dim , Complex* center) {
    double w = dim->re;
    double h = dim->im;

    double centerX = center->re;
    double centerY = center->im;

    double left = centerX - w/2;
    double right = centerX +  w/2;
    double top = centerY + h/2;
    double bottom = centerY - h/2;

    Boundaries bound = { left , right , top , bottom };
    return bound;
}
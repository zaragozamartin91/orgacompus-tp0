#include <math.h>
#include <stdio.h>

#include "complex.h"

Complex pow2Cpx(Complex value) {
  double re = value.re * value.re - value.im * value.im;
  double im = 2 * value.re * value.im;
  Complex square = {re, im};
  return square;
}

Complex addCpx(Complex first , Complex second) {
  double re = first.re + second.re;
  double im = first.im + second.im;
  Complex cpx = {re , im};
  return cpx;
}

double modCpx(Complex value) {
  double t = value.re * value.re + value.im * value.im;
  return sqrt(t);
}

Complex parseCpx(char* str) {
  double re;
  char op;
  double im;
  sscanf(str , "%lf%lf", &re , &im);
  printf("valor: %lf %lfi\n" , re , im);
  Complex cpx = {re , im};
  return cpx;
}


Complex mapPixel(Pixel pixel, Resolution resolution, Dimension cpxSize, Complex center) {
  // TODO
  Complex complex = {1.2, 2.54};

  Boundaries bound = getBoundaries(&cpxSize , &center);

  return complex;
}

Boundaries getBoundaries(Dimension* dim , Complex* center) {
    double w = dim->width;
    double h = dim->height;

    double centerX = center->re;
    double centerY = center->im;

    double left = centerX - w/2;
    double right = centerX +  w/2;
    double top = centerY + h/2;
    double bottom = centerY - h/2;

    Boundaries bound = { left , right , top , bottom };
    return bound;
}
#include "complex.h"
#include <math.h>

Complex squareCpx(Complex value) {
  double re = value.re * value.re - value.im * value.im;
  double im = 2 * value.re * value.im;
  Complex square = {re, im};
  return square;
}

double modCpx(Complex value) {
  double t = value.re * value.re + value.im * value.im;
  return sqrt(t);
}

Complex mapPixel(Pixel pixel, Resolution resolution, Dimension cpxSize, Complex center) {
  Complex complex = {1.2, 2.54};
  return complex;
}
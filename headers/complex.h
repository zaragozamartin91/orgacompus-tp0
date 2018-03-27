#ifndef COMPLEX_H
#define COMPLEX_H

#include "pixel.h"

typedef struct {
    double re;
    double im;
} Complex;

Complex squareCpx(Complex value);

/** 
 * Obtiene el modulo de un valor complejo (distancia respecto al origen).
*/
double modCpx(Complex value);

/** 
 * Convierte un pixel en un valor complejo
*/
Complex mapPixel(Pixel pixel , Resolution resolution , Dimension cpxSize , Complex center);

#endif
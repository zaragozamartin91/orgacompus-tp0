#ifndef COMPLEX_H
#define COMPLEX_H

#include "pixel.h"

typedef struct {
    double re;
    double im;
} Complex;

/** 
 * 
*/
Complex mapPixel(Pixel pixel , Resolution resolution , Dimension cpxSize , Complex center);

#endif
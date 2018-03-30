#ifndef COMPLEX_H
#define COMPLEX_H

#include "pixel.h"

typedef struct {
    double re;
    double im;
} Complex;

typedef struct {
    double left;
    double right;
    double top;
    double bottom;
} Boundaries;

Complex newCpx(double re , double im);

/** 
 * Obtiene un numero complejo a partir de un string
*/
Complex parseCpx(char* str);

/**
 * Obtiene la raiz cuadrada de un complejo
 */
Complex pow2Cpx(Complex* value);

Complex addCpx(Complex* first , Complex* second);

/** 
 * Obtiene el modulo de un valor complejo (distancia respecto al origen).
*/
double modCpx(Complex* value);

/** 
 * Calcula los limites del plano complejo (el rectangulo a mapear del plano complejo).
 * Dimension dim - Tamano del plano complejo
 * Complex center - Valor de centro EN EL plano
*/
Boundaries getBoundaries(Complex* dim , Complex* center);

#endif
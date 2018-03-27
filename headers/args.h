#ifndef ARGS_H
#define ARGS_H

#include "pixel.h"
#include "complex.h"

typedef struct {
    Resolution resolution;  // resolucion de imagen
    Complex center;         // centro del plano complejo
    Dimension cpxSize;      // tamano del plano complejo
    Complex seed;           // semilla disparadora
    char* outfile;          // archivo de salida
} Arguments;

Arguments parseArgs(int argc, char** args);

#endif
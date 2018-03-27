#ifndef ARGS_H
#define ARGS_H

#include "pixel.h"
#include "complex.h"

typedef struct {
    Resolution resolution;
    Complex center;
    Dimension cpxSize;
    Complex seed;
    char* outfile;
} Arguments;

Arguments parseArgs(int argc, char** args);

#endif
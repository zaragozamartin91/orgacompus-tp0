#include <stdlib.h>
#include <stdio.h>
#include "julia.h"
#include "complex.h"

typedef unsigned char byte;

byte iterateCpx(Complex cpx , Complex seed) {
    double mod = modCpx(cpx);
    byte res = 0;
    while(mod < 2 && res < 255) {
        Complex pow = pow2Cpx(cpx);
        Complex newCpx = addCpx(pow , seed);
        mod = modCpx(newCpx);
        res++;
    }
    return res;
}

void run(Arguments args) {
    Dimension cpxDim = args.cpxSize;
    Complex cpxCenter = args.center;
    Boundaries bound = getBoundaries(cpxDim , cpxCenter);

    Resolution resolution = args.resolution;

    double stepX = resolution.width / cpxDim.width;
    double stepY = resolution.height / cpxDim.height;

    Complex seed = args.seed;

    unsigned itemCount = resolution.width * resolution.height;
    byte *values = malloc( sizeof(byte) * itemCount );

    for(int y = 0 ; y < resolution.height ; y++) {
        double imMap = y * stepY + bound.top;
        
        for(int x = 0 ; x < resolution.width ; x++) {
            double reMap = x * stepX + bound.left;

            Complex cpx = { reMap , imMap };
            byte value = iterateCpx(cpx , seed);

            unsigned index = y * resolution.width + x;
            values[index] = value;
        }
    }

    free(values);    
}


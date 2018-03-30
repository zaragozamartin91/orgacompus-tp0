#include <stdlib.h>
#include <stdio.h>
#include "julia.h"
#include "complex.h"

typedef unsigned char byte;

void printCpx(Complex* cpx, char* prefix) {
    printf("%s%.*f,%.*f", prefix , 10 , cpx->re , 10 , cpx->im);
}


byte iterateCpx(Complex cpx , Complex seed) {
    double mod = modCpx(&cpx);
    int res = 0;
    Complex itCpx = cpx;

    if(mod >= 2.0) {
        printf("\tmod = %lf\n" , mod);
        return res;
    }

    //printf("mod for complex %lf,%lf is %lf \n" , cpx.re , cpx.im , mod);
    while(mod < 2 && res++ < 255) {
        Complex powCpx = pow2Cpx(&itCpx);
        //printf("\tpow2Cpx: ");
        //printCpx(&powCpx);
        //printf("\n");

        Complex newCpx = addCpx(&powCpx , &seed);
        //printf("\taddCpx: ");
        //printCpx(&newCpx);
        //printf("\n");

        mod = modCpx(&newCpx);
        printf("\tmod = %lf\n" , mod);
        
        itCpx = newCpx;
        printCpx(&itCpx , "\tnewCpx: ");
        printf("\n");
    }
    return res >= 255 ? 255 : (byte) res;
}

void printMatrix(byte *values, Resolution* resolution) {
    int items = resolution->height * resolution->width;
    for(int i = 0; i < items ; i++) {
        if(i % resolution->width == 0) printf("\n");
        printf("%d " , values[i]);
    }
    printf("\n");
}

void runJulia(Arguments* args) {
    Dimension cpxDim = args->cpxSize;
    Complex cpxCenter = args->center;
    Boundaries bound = getBoundaries(&cpxDim , &cpxCenter);

    printf("Boundaries: %lf,%lf,%lf,%lf \n" , bound.left , bound.right , bound.top , bound.bottom);

    Resolution resolution = args->resolution;

    double stepX = ( (double) cpxDim.width) / ( (double) resolution.width);
    double stepY = ( (double) cpxDim.height) / ( (double) resolution.height);

    printf("stepX: %lf , stepY: %lf \n" , stepX , stepY);

    Complex seed = args->seed;

    unsigned itemCount = resolution.width * resolution.height;
    byte *values = malloc( sizeof(byte) * itemCount );

    for(int y = 0 ; y < resolution.height ; y++) {
        double imMap = y * stepY + bound.top;
        
        for(int x = 0 ; x < resolution.width ; x++) {
            double reMap = x * stepX + bound.left;

            Complex cpx = newCpx(reMap , imMap);
            printCpx(&cpx , "this step: ");
            printf("\n");

            byte value = iterateCpx(cpx , seed);

            unsigned index = y * resolution.width + x;
            values[index] = value;
        }
    }

    printMatrix(values , &resolution);

    free(values);    
}


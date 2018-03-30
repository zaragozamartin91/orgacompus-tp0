#include <stdlib.h>
#include <stdio.h>
#include "julia.h"
#include "complex.h"
#include "utils.h"
#include "string.h"

typedef unsigned char byte;

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
        printf("\tmod = %lf ; " , mod);
        
        itCpx = newCpx;
        printCpx(&itCpx , "newCpx: ");
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

unsigned getOptIndex(unsigned itemCount) {
    unsigned idx = 16;
    while(itemCount % idx-- > 0);
    return idx + 1;
}

void runJulia(Arguments* args) {
    Complex cpxDim = args->cpxSize;
    Complex cpxCenter = args->center;
    Boundaries bound = getBoundaries(&cpxDim , &cpxCenter);


    Resolution resolution = args->resolution;

    double stepX = ( (double) cpxDim.re) / ( (double) resolution.width);
    double stepY = ( (double) cpxDim.im) / ( (double) resolution.height);


    Complex seed = args->seed;

    unsigned itemCount = resolution.width * resolution.height;
    byte *values = malloc( sizeof(byte) * itemCount );

    
    int coutMode = 0; //false
    char* outfilePath = args->outfile;
    coutMode = strcmp("" , outfilePath) == 0 || strcmp("cout" , outfilePath) == 0;
    if(coutMode) printf("MODO COUT ACTIVO\n");
    FILE* outfile = coutMode ? stdout : fopen(outfilePath , "w");

    if(outfile == NULL) {
        printf("El archivo %s no existe!\n" , outfilePath);
        return;
    }

    fprintf(outfile,"P2\n");
    fprintf(outfile , "%d %d\n" , resolution.width , resolution.height);
    fprintf(outfile,"%d" , 255);

    // indice optimo para introducir un ENTER en el archivo PGM
    unsigned optIndex = getOptIndex(itemCount);

    double imMap;
    double reMap;
    int y;
    int x;
    unsigned index = 0;
    for(y = 0 ; y < resolution.height ; y++) {
        imMap = ((double)y) * stepY * (-1.0) + bound.top;
        
        for(x = 0 ; x < resolution.width ; x++) {
            reMap = ((double)x) * stepX + bound.left;

            Complex cpx = newCpx(reMap , imMap);
            printCpx(&cpx , "this step: ");
            printf("\n");

            byte value = iterateCpx(cpx , seed);

            if(index % optIndex == 0) fprintf(outfile , "\n");
            fprintf(outfile , "%d " , value);

            //index = y * resolution.width + x;
            values[index] = value;

            ++index;
        }
    }

    fflush(outfile);
    if(!coutMode) fclose(outfile);

    //printMatrix(values , &resolution);

    free(values);    
    
    printf("stepX: %lf , stepY: %lf \n" , stepX , stepY);
    printf("Boundaries: %lf,%lf,%lf,%lf \n" , bound.left , bound.right , bound.top , bound.bottom);
}


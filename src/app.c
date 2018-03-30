#include <stdio.h>

#include "pixel.h"
#include "complex.h"
#include "args.h"
#include "julia.h"
#include "utils.h"

int main(int argc, char** argv) {
    FILE* file = stdout;
    fprintf(file , "hola\n");
    fflush(stdout);


    Resolution res = parseRes("10x10");
    printf("Resolution: %ux%u\n" , res.width , res.height);

    Complex seed = parseCpx("-0.726895347709114071439+0.188887129043845954792i");
    printCpx(&seed , "Seed: ");
    printf("\n");

    int Digs = 21;
    double OneSeventh = 1.0/7.0;
    printf("%.*f\n", Digs, OneSeventh);

    /* 
    Resolution resolution;  // resolucion de imagen
    Complex center;         // centro del plano complejo
    Dimension cpxSize;      // tamano del plano complejo
    Complex seed;           // semilla disparadora
    char* outfile;          // archivo de salida
    */
    Complex center = newCpx(0.0 , 0.0);
    Dimension cpxSize = {2,2};
    char* outfile = "";
    Arguments args = {res , center , cpxSize , seed , outfile};

    runJulia(&args);

    return 0;
}
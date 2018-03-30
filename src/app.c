#include <stdio.h>

#include "pixel.h"
#include "complex.h"
#include "args.h"
#include "julia.h"
#include "utils.h"

int main(int argc, char** argv) {
    Arguments args = parseArgs(argc, argv);

    //Resolution res = { 1 , 1 };
    //parseRes("10x10" , &res);
    //
    //Complex seed = { 0.0 , 0.0 };
    //parseCpx("-0.726895347709114071439+0.188887129043845954792i" , &seed);

//    int Digs = 21;
//    double OneSeventh = 1.0/7.0;
//    printf("%.*f\n", Digs, OneSeventh);

    /* 
    Resolution resolution;  // resolucion de imagen
    Complex center;         // centro del plano complejo
    Dimension cpxSize;      // tamano del plano complejo
    Complex seed;           // semilla disparadora
    char* outfile;          // archivo de salida
    */
    
    //Complex center = newCpx(0.0 , 0.0);
    //Complex cpxSize = {2.0,2.0};
    //char* outfile = "out.pgm";
    //Arguments args = {res , center , cpxSize , seed , outfile};

    runJulia(&args);

    printCpx(&args.center , "Centro: ");
    printf("\n");
    printCpx(&args.seed , "Seed: ");
    printf("\n");
    printf("Resolution: %ux%u\n" , args.resolution.width , args.resolution.height);
    printCpx(&args.cpxSize , "Tamano plano complejo: ");
    printf("\n");
    printf("Salida: %s\n" , args.outfile);

    return 0;
}
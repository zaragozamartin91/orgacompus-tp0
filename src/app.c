#include <stdio.h>

#include "pixel.h"
#include "complex.h"
#include "args.h"
#include "julia.h"
 
int main(int argc, char** args) {
    Resolution res = parseRes("640x480");
    printf("%ux%u\n" , res.width , res.height);

    Complex cpx = parseCpx("-0.123456789012345678901-7.89i");

    int Digs = 21;
    double OneSeventh = 1.0/7.0;
    printf("%.*f\n", Digs, OneSeventh);

    return 0;
}
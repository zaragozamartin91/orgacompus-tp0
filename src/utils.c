#include <stdio.h>
#include "utils.h"

void printCpx(Complex* cpx, char* prefix) {
    printf("%s%.*f,%.*f", prefix , 10 , cpx->re , 10 , cpx->im);
}



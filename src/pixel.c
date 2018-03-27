#include <stdio.h>

#include "pixel.h"

Resolution parseRes(char* str) {
    unsigned w;
    unsigned h;
    sscanf(str , "%ux%u" , &w , &h);
    Resolution res = { w , h };
    return res;
}

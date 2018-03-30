#include <stdio.h>

#include "pixel.h"

void parseRes(char* str , Resolution* targetRes) {
    unsigned w;
    unsigned h;
    int scanResult = sscanf(str , "%ux%u" , &w , &h);
    if(scanResult == 2) {
        targetRes->height = h;
        targetRes->width = w;
    }
}

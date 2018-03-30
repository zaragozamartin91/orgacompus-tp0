#ifndef PIXEL_H
#define PIXEL_H

typedef struct {
    unsigned x;
    unsigned y;
} Pixel;

typedef struct {
    unsigned width;
    unsigned height;  
} Dimension;

typedef Dimension Resolution;

void parseRes(char* str , Resolution* targetRes);

#endif
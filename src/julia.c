#include "julia.h"
#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "string.h"
#include "utils.h"

typedef unsigned char byte;

byte iterateCpx(Complex cpx, Complex seed) {
  double mod = modCpx(&cpx);
  int res = 0;
  Complex itCpx = cpx;

  if (mod >= 2.0) {
    return res;
  }

  Complex powCpx;
  Complex newCpx;

  while (mod < 2 && res++ < 255) {
    powCpx = pow2Cpx(&itCpx);
    newCpx = addCpx(&powCpx, &seed);
    
    mod = modCpx(&newCpx);

    itCpx = newCpx;
    
  }
  return res >= 255 ? 255 : (byte)res;
}

unsigned getOptIndex(unsigned itemCount) {
  unsigned idx = 16;
  while (itemCount % idx-- > 0)
    ;
  return idx + 1;
}

void runJulia(Arguments* args) {
  Complex cpxDim = args->cpxSize;
  Complex cpxCenter = args->center;
  Boundaries bound = getBoundaries(&cpxDim, &cpxCenter);

  Resolution resolution = args->resolution;

  double stepX = ((double)cpxDim.re) / ((double)resolution.width);
  double stepY = ((double)cpxDim.im) / ((double)resolution.height);

  Complex seed = args->seed;

  unsigned itemCount = resolution.width * resolution.height;

  int coutMode = 0;  // false
  char* outfilePath = args->outfile;
  coutMode = strcmp("", outfilePath) == 0 || strcmp("cout", outfilePath) == 0;
  
  FILE* outfile = coutMode ? stdout : fopen(outfilePath, "w");

  if (outfile == NULL) {
    printf("El archivo %s no existe!\n", outfilePath);
    return;
  }

  fprintf(outfile, "P2\n");
  fprintf(outfile, "%d %d\n", resolution.width, resolution.height);
  fprintf(outfile, "%d", 255);

  // indice optimo para introducir un ENTER en el archivo PGM
  unsigned optIndex = getOptIndex(itemCount);

  double imMap;
  double reMap;
  int y;
  int x;
  unsigned index = 0;
  for (y = 0; y < resolution.height; y++) {
    imMap = ((double)y) * stepY * (-1.0) + bound.top;

    for (x = 0; x < resolution.width; x++) {
      reMap = ((double)x) * stepX + bound.left;

      Complex cpx = newCpx(reMap, imMap);
      
      byte value = iterateCpx(cpx, seed);

      if (index % optIndex == 0) fprintf(outfile, "\n");
      fprintf(outfile, "%d ", value);

      ++index;
    }
  }

  fprintf(outfile, "\n");
  fflush(outfile);
  if (!coutMode) fclose(outfile);

}

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
    // printf("\tmod = %lf\n" , mod);
    return res;
  }

  Complex powCpx;
  Complex newCpx;

  // printf("mod for complex %lf,%lf is %lf \n" , cpx.re , cpx.im , mod);
  while (mod < 2 && res++ < 255) {
    powCpx = pow2Cpx(&itCpx);
    // printf("\tpow2Cpx: ");
    // printCpx(&powCpx);
    // printf("\n");

    newCpx = addCpx(&powCpx, &seed);
    // printf("\taddCpx: ");
    // printCpx(&newCpx);
    // printf("\n");

    mod = modCpx(&newCpx);
    // printf("\tmod = %lf ; " , mod);

    itCpx = newCpx;
    // printCpx(&itCpx , "newCpx: ");
    // printf("\n");
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
  //if (coutMode) printf("MODO COUT ACTIVO\n");
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
      // printCpx(&cpx , "this step: ");
      // printf("\n");

      byte value = iterateCpx(cpx, seed);

      if (index % optIndex == 0) fprintf(outfile, "\n");
      fprintf(outfile, "%d ", value);

      ++index;
    }
  }

  fprintf(outfile, "\n");
  fflush(outfile);
  if (!coutMode) fclose(outfile);

  //printf("stepX: %lf , stepY: %lf \n", stepX, stepY);
  //printf("Boundaries: left:%lf,right:%lf,top:%lf,bottom:%lf \n", bound.left,
 //        bound.right, bound.top, bound.bottom);
}

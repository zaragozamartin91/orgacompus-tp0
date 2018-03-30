#include <getopt.h>
#include <stdio.h> /* for printf */
#include "args.h"
#include "pixel.h"
#include "utils.h"

Arguments parseArgs(int argc, char** argv) {
  int c;

  Resolution resolution = { 640 , 480 };
  Complex center = {0.0 , 0.0};
  double cpxw = 2.0;
  double cpxh = 2.0;
  Complex seed = { -0.726895347709114071439 , 0.188887129043845954792 };
  char* outfile;

  while (1) {
    int option_index = 0;
    
    // SETEANDO opterr = 0 se logra que getopt no imprima sus propios mensajes
    opterr = 0;
    static struct option long_options[] = {{"resolution", optional_argument, 0, 0},
                                           {"center", optional_argument, 0, 0},
                                           {"width", optional_argument, 0, 0},
                                           {"height", optional_argument, 0, 0},
                                           {"seed", optional_argument, 0, 0},
                                           {"output", optional_argument, 0, 0},
                                           {0, 0, 0, 0}};

    c = getopt_long(argc, argv, "r:c:w:H:s:o:", long_options, &option_index);
    if (c == -1) break;

    switch (c) {
      case 0:
        switch(option_index) {
          case 0:
            parseRes(optarg , &resolution); break;
          case 1:
            parseCpx(optarg , &center); break;
          case 2:
            sscanf(optarg , "%lf" , &cpxw); break;
          case 3:
            sscanf(optarg , "%lf" , &cpxh); break;
          case 4:
            parseCpx(optarg , &seed); break;
          case 5:
            outfile = optarg; break;
          default: break;
        }
        break;

      case 'r':
        parseRes(optarg , &resolution);        
        break;

      case 'w':
        sscanf(optarg , "%lf" , &cpxw);
        break;

      case 'H':
        sscanf(optarg , "%lf" , &cpxh);
        break;

      case 's':
        parseCpx(optarg , &seed);
        break;

      case 'o':
        outfile = optarg;
        break;

      case 'c':
        parseCpx(optarg , &center);
        break;

      case '?':
        printf("option ? with value '%s'\n", optarg);
        break;

      default:
        printf("?? getopt returned character code 0%o ??\n", c);
    }
  }

  if (optind < argc) {
    printf("non-option ARGV-elements: ");
    while (optind < argc) printf("%s ", argv[optind++]);
    printf("\n");
  }

  //  Resolution resolution;
  //  Complex center;
  //  Complex cpxSize;
  //  Complex seed;
  //  char* outfile;
  Complex cpxSize = {cpxw , cpxh};
  Arguments arguments = {resolution , center , cpxSize , seed , outfile};

  return arguments;
}


#include "args.h"
#include <getopt.h>
#include <stdio.h> /* for printf */

Arguments parseArgs(int argc, char** argv) {
  Arguments arguments;

  int c;
  int digit_optind = 0;

  while (1) {
    int this_option_optind = optind ? optind : 1;
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
        printf("option %s", long_options[option_index].name);
        if (optarg) printf(" with arg %s", optarg);
        printf("\n");
        break;

      case 'r':
        printf("option r with value '%s'\n", optarg);
        break;

      case 'w':
        printf("option w with value '%s'\n", optarg);
        break;

      case 'H':
        printf("option H with value '%s'\n", optarg);
        break;

      case 's':
        printf("option s with value '%s'\n", optarg);
        break;

      case 'o':
        printf("option o with value '%s'\n", optarg);
        break;

      case 'c':
        printf("option c with value '%s'\n", optarg);
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

  return arguments;
}
#include <stdio.h>

#include "pixel.h"
#include "complex.h"
#include "args.h"
#include "julia.h"
#include "utils.h"

int main(int argc, char** argv) {
    Arguments args = parseArgs(argc, argv);

    runJulia(&args);

    return 0;
}


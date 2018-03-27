#include "args.h"

#include <stdio.h>
 
int main() {
    Argument arg = {123};
    printf("My id is %d\n" , arg.data);
    return 0;
}
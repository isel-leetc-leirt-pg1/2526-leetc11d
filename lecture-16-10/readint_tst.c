#include <stdio.h>
#include "utils.h"


// lê um valor entre 1 e 10
int main() {

    int n = read_int(1,10);
    printf("foi lido o número: %d\n", n);
    return 0;
    
}
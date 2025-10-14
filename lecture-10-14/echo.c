/**
 * Este programa ecoa uma linha lida da consola
 */

#include <stdio.h>
 

int main() {
    
    char car;

    printf("linha? ");
    
    do {
        // scanf("%c", &car);
        // printf("%c", car);

        car = getchar();
        putchar(car);

    }
    while (car != '\n');
    // to complete
  
    return 0;
    
}
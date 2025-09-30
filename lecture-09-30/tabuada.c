/**
 * Este programa apresenta a tabuada do número dado
 * (de 1 a 10)
 */
#include <stdio.h>

int main() {
    int n;

    printf("qual a tabuada (1 a 10)? ");
    scanf("%d", &n);

    if (n < 1 || n > 10 ) {
        printf("valor inválido!\n");
        return 1;
    }
    int i = 1;
    while (i <= 10) {
        // modifique o printf de modo a que a tabuada apareça devidamente tabulada
        printf("%d x %d = %d\n", n, i, n*i);
        i = i + 1;
    }
    return 0;
}
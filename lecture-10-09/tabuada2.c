#include <stdio.h>

/**
 * Apresenta na consola a tabuada do número "n"
 * recebido por parâmetro
 */
void tabuada(int n) {
    printf("Tabuada do %d:\n\n", n);
    for(int i = 1; i <= 10; ++i) {
        printf("%2d x %2d = %2d\n", n, i, n*i);
    }
}

int main() {
    int num;

    printf("n? ");
    scanf("%d", &num);

    tabuada(num);
    return 0;
}
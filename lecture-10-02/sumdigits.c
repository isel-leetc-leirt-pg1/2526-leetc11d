#include <stdio.h>

/**
 * retorna a soma dos dígitos do número "n"
 * passado por parâmetro
 */
int sum_digits(int n) {
    int sum = 0;
    while(n > 0) {
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}

int main() {
    int v;

    printf("número inteiro positivo? ");
    scanf("%d", &v);

    int sd = sum_digits(v);

    printf("a soma dos dígitos de %d é %d\n", v, sd);
    return 0;
}
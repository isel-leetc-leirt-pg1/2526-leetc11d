#include <stdio.h>

/**
 * Esta função retorna a contagem
 * dos algarismos do número "n" recebido por parâmetro
 */
int num_digits(int n) {
    int count = 0;
    do {
        count = count +1;
        n = n / 10;
    }
    while (n > 0);
    return count;
}

int main() {
    int v;

    printf("indique o valor: ");
    scanf("%d", &v);
    int nd = num_digits(v);
    printf("O número %d tem %d algarismos\n", v, nd);
    return 0;
}
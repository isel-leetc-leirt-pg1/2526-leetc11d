#include <stdio.h>


#define MAX_SIZE 1000

int main() {
    int vals[MAX_SIZE];

    int n; // valor lido
    int p = 0; // indice atual no array

    printf("introduza uma sequência de inteiros terminada por 0: ");
    
    // ciclo de leitura da sequência
    do {

        scanf("%d", &n);
        if (n != 0) {
            vals[p] = n;
            p++;
        }
    }
    while( p < MAX_SIZE && n != 0);
  
    // ciclo para cálculo da soma dos valores
    long total = 0;
    for(int i= 0; i < p; ++i) {
        total = total + vals[i]; // ou total+= vals[i];
    }

    long mean = total/p;

    // ciclo de apresentação doa valores superiores à média

    printf("média: %ld\n", mean);
    printf("valores maiores do que a média:\n");

    int show_count = 0;
    for(int i= 0; i < p; ++i) {
        if (vals[i] > mean) {
           
            printf("%d\n", vals[i]);
             ++show_count;
        }
    }
    printf("total de maiores: %d\n", show_count);
    return 0;

}
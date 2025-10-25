#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include <stdbool.h>

/**
 * define uma nova semente (valor inicial) para o gerador pseudo-aleatório
 * relacionada com o tempo de calendário
 */
void random_init() {
    srand(time(NULL));
}

/**
 * retorna um valor aleatório dentro dos limites
 * especificados por parâmetro (intervalo fechado)
 */
int random_range(int start, int end) {
    return rand() % (end-start+1) + start;
}

/**
 * ler um valor inteiro garantindo 
 * que está dentro do intervalo especificado
 */
int read_int(int start, int end) {
    int n;

    do {
        printf("num? ");
        int res = scanf("%d", &n);
        if (res == 1 && n >= start && n <= end && getchar() == '\n') {
            return n;
        }
       
        // mensagem de erro
        printf("valor inválido!\n");
        // limpar o buffer de input
        while(getchar() != '\n');

        // o código comentado a seguir
        // é equivalente ao while anterior
        // int c;
        // do {
        //     c = getchar();
        // }
        // while(c != '\n');
    }
    while(true);

}


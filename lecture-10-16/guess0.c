/**
 * Este programa é um jogo em que o utilizador tenta adivinhar um número 
 * dentro de um intervalo, usando um nṹmero limitado de tentativas.
 */


#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <stdbool.h>

#define MAX_NUM 100
 
int game(int max_tries) {
    int n_tries = 0;
    int num;
    int secret = random_range(1, MAX_NUM);
    do {
        ++n_tries;
        printf("%dª tentativa: ", n_tries);
        //scanf("%d", &num);
        num = read_int(1, 100);

        if (num > secret) {
            printf("maior!\n");
        }
        else if (num < secret) {
            printf("menor!\n");
        }
        else {
            return n_tries;
        }
        
    }
    while(n_tries < max_tries);
    return -1;
}

int main() {
    int max_tries;

    random_init();
    printf("max. tentativas? ");
    scanf("%d", &max_tries);

    char option;
    do {
        int res = game(max_tries);

        if (res == -1) {
            printf("perdeu! Talvez para a próxima\n");
        }
        else {
            printf("parabéns! venceu o jogo em %d tentativas\n", res);
        }
        printf("pretende jogar de novo (s,n)? ");
        scanf("%c", &option);
       
        //printf("código do caracter lido: %d\n", option);
    }
    while(option == 's' || option == 'S');

    printf("até à próxima!\n");
    return 0;
   
}

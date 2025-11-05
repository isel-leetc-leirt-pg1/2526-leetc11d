/**
 * Este programa procura uma sequência de carateres dada no
 * input recebido
 * Utiliza como suporte as funções "fgets" e "strstr"
 * da biblioteca de "C" para ler uma linha do input e procurar se
 * a sequência de carateres existe na linha, respectivamente.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool pg_getline(char line[], int maxline) {
    if (fgets(line, maxline, stdin) == NULL) return false;
    return true;
    
}


int pg_strstr(char s1[], char s2[]) {
    if (strstr(s1, s2) == NULL) return -1;
    return 0;
}

int main() {
    char tofind[] = "human";
    char line[256];
    int nline = 0;

    while(pg_getline(line, 256) == true) {
        nline++;
        printf("linha %d: %s\n", nline, line);
        
        if (pg_strstr(line, tofind) != -1) {
            printf("%d: %s", nline, line);
        }
    }
    return 0;
}
/**
 * programa procura uma sequência de carateres dada
 * no input recebido
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool pg_getline(char line[], int maxline) {
    // if (fgets(line, maxline, stdin) == NULL) return false;
    // return true;
    int nc = 0; // contader de carateres lidos
    int c; // carater lido

    while ( nc < maxline && (c= getchar()) != '\n' && c != -1) {
        // se couber, e não for mudança de linha ou -1, adicionar a "line"
        line[nc] = c;
        nc++;
    }
    // terminar "line"
    line[nc] = 0;
    
    // retornar "false" se o input chegou ao fim
    return nc != 0 || c != -1;
}


int pg_strstr(char s1[], char s2[]) {
    
    int i1 = 0, i2;

    while(s1[i1] != 0) {
        i2 = 0;
        while(s1[i1+i2] == s2[i2] && s2[i2] != 0) {
            i2++;
        }
        // se chegou ao fim de "s2" retornar a posição onde encontrou
        if (s2[i2] == 0) {
            return i1;
        }
        // avançar "i1"
        ++i1;
    }
    return -1; // a string "s2" não foi encontrada em "s1"
}

int main() {
    char tofind[] = "human";
    char line[256];
    int nline = 0;

    while(pg_getline(line, 256) == true) {
        nline++;
           
        if (pg_strstr(line, tofind) != -1) {
            printf("%d: %s\n", nline, line);
        }
    }
    return 0;
}
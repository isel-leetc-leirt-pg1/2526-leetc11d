/**
 * Mostrar a ocorrência de cada letra do alfabeto no texto indicado
 */
#include <stdio.h>
#include <ctype.h>

 #define NLETTERS ('Z' - 'A' + 1)

 int main() {
    // declarar e iniciar o array letters com zeros
    int letters[NLETTERS] = {0};

    // fase de contabilização
    int c;

    while ((c = getchar()) != -1) {
        if (isalpha(c)) {
            // incrementar as ocorrências da respetiva letra
            c = toupper(c);
            letters[ c - 'A' ]++;
        }
    }

    // fase de apresentação

    for(int i=0; i < NLETTERS; ++i) {
        printf("%c: %03d\n", 'A' + i, letters[i]);
    }

    return 0;
 }

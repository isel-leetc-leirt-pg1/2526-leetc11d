/**
 * Mostrar a ocorrência de cada letra do alfabeto no texto indicado
 */
#include <stdio.h>
#include <ctype.h>

#define NLETTERS ('Z' - 'A' + 1)

// dimensão da barra para a máxima ocorrência
#define MAX_COLUMN 60

typedef int histogram_t[NLETTERS];

void histo_collect(histogram_t histo) {
    int c;

    while ((c = getchar()) != -1) {
        if (isalpha(c)) {
            // incrementar as ocorrências da respetiva letra
            c = toupper(c);
            histo[ c - 'A' ]++;
        }
    }
}

/**
 * Mostrar simplesmente o núemro de ocorrências para cada letra,
 * por ordem alfabética
 */
void histo_show1(histogram_t histo) {
    for(int i=0; i < NLETTERS; ++i) {
        printf("%c: %4d\n", 'A' + i, histo[i]);     
    }
}


/**
 * Mostrar, para cada letra, por ordem alfabética, o número de ocorrências da letra e uma
 * barra horizontal proporcional ao número de ocorrências
 */
void histo_show2(histogram_t histo) {
    // TODO
}

/**
 * Mostrar, para cada letra, por ordem de ocorrências, o número de ocorrências da letra e uma
 * barra horizontal proporcional ao número de ocorrências
 */
void histo_show3(histogram_t histo) {
     // TODO
}


int main() {
    // declarar e iniciar o array "histo" com zeros
    histogram_t histo = {0};

    // fase de contabilização
    histo_collect(histo);

    // fase de apresentação
    histo_show1(histo);
    
    return 0;
 }

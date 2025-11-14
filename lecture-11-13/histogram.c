/**
 * Mostrar a ocorrência de cada letra do alfabeto no texto indicado
 */
#include <stdio.h>
#include <ctype.h>

#define NLETTERS ('Z' - 'A' + 1)
#define MAX_COLUMN 60

typedef int histogram_t[NLETTERS];

typedef struct letter_count {
    char letter;
    int ocurrs;
} letter_count_t;


int lc_compare(letter_count_t lc1, letter_count_t lc2) {
    return lc1.ocurrs - lc2.ocurrs;
}


void histo_copy(histogram_t histo, letter_count_t lc[]) {
    for(int i=0; i < NLETTERS; ++i) {
        lc[i].ocurrs = histo[i];
        lc[i].letter = 'A' + i;
    }
}

int lc_cmp(letter_count_t lc1, letter_count_t lc2) {
    // if (lc1.ocurrs > lc2.ocurrs) {
    //     return 1;
    // }
    // else if (lc1.ocurrs < lc2.ocurrs) {
    //     return -1;
    // }
    // else {
    //     return 0;
    // }
    return lc1.ocurrs - lc2.ocurrs;
}

void lc_sort(letter_count_t lc[NLETTERS]) {
    for (int i = NLETTERS-1; i > 0; --i) {
        letter_count_t greater = lc[0];
        int idx_greater = 0;


        for(int j=0; j <= i; ++j) {
            if ( lc_cmp(lc[j], greater) > 0) {
                greater = lc[j];
                idx_greater = j;
            }
        }

        lc[idx_greater] = lc[i];
        lc[i] = greater;
    }
  
}


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

int histo_max_occur(histogram_t histo) {
    int m = histo[0];
    for(int i = 1; i < NLETTERS; ++i) {
        if (histo[i] > m) {
            m = histo[i];
        }
    }
    return m;
}

int normalize(int val, int max) {
    int r =  (val * MAX_COLUMN) / max;
    if (r == 0) r = 1;
    return r;
}

void histo_show(histogram_t histo) {
    int max = histo_max_occur(histo);
    for(int i=0; i < NLETTERS; ++i) {
        printf("%c(%4d): ", 'A' + i, histo[i]);
        int bar_size = normalize(histo[i], max);
        for(int j =0; j < bar_size; ++j) {
            putchar('*');
        }
        putchar('\n');
    }

}


void histo_show2(histogram_t histo) {
    letter_count_t lc[NLETTERS];

    histo_copy(histo, lc);

    lc_sort(lc);

    int max = histo_max_occur(histo);
    for(int i=NLETTERS-1; i >= 0; --i) {
        printf("%c(%4d): ", lc[i].letter, lc[i].ocurrs);
        int bar_size = normalize(lc[i].ocurrs, max);
        for(int j =0; j < bar_size; ++j) {
            putchar('*');
        }
        putchar('\n');
    }

}


int main() {
    // declarar e iniciar o array "histo" com zeros
    histogram_t histo = {0};

    // fase de contabilização
    histo_collect(histo);

    // fase de apresentação por ordem de ocorrências
    histo_show2(histo);
    
    return 0;
 }

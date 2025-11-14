#include <stdbool.h>

void bubble_sort(int vals[], int nvals)  {
    bool troca = true;

    for(int i= nvals-1; i > 0 && troca; --i) {
        troca = false;
        for(int j = 0; j < i; j++) {
            if (vals[j] > vals[j+1]) {
                int tmp = vals[j];
                vals[j] = vals[j+1];
                vals[j+1] = tmp;
                troca = true;
            }
        }
    }
}

void selection_sort(int vals[], int nvals) {
    for(int i= nvals-1; i > 0 && troca; --i) {
        int greater = vals[0];
        int idx_greater = 0;
        for(int j = 1; j <= i; ++j) {
            if (vals[j] > greater) {
                greater = vals[j];
                idx_greater = j;
            }
        }
        // trocar o maior com a última posição
        vals[idx_greater] = vals[i];
        vals[i] = greater;
    }

}

void insertion_sort(int vals[], int nvals) {
    // TODO
}

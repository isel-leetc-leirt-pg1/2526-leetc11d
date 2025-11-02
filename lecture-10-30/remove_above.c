#include <stdio.h>

/**
 * Mostra os elementos do array de inteiros recebido por parâmetro
 */
void show_array(int vals[], int size) {
    // bad thing int values_size = sizeof(vals)/sizeof(vals[0]);
    printf("[");
    if (size > 0) {
        printf("%d", vals[0]);
        for(int i=1; i < size; ++i) {
          printf(", %d", vals[i]);
         }
    }
   
    printf("]\n");
}

/**
 * Descrição:
 *  Remove de um array de inteiros todos os elementos
 *  acima de determinado valor, mantendo a ordem dos elementos
 *  restantes
 * Retorna:
 *   total de valores restantes
 */
int remove_above(int vals[], int size, int max) {
    int iget = 0, iput = 0;

    while(iget < size) {
        if (vals[iget] <= max) {
            vals[iput++] = vals[iget];
        }
        iget++;
    }
    return iput;

}


int main() {
    int values[] = { 3, 7, 10, 1, 5, 4, 8, 8, 2, 2};

    //int vals_bytes_size = sizeof(values);
    int values_size = sizeof(values)/sizeof(values[0]);

    int new_size = remove_above(values, values_size, 6);

    show_array(values, new_size);
    return 0;
}
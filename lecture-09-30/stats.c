/**
 * Este programa determina se uma sequência de números inteiros positivos está ou não ordenada,
 * por ordem crescente ou decrescente, ou se todos os elementos são iguais.
 * A sequência termina quando for introduzido o valor 0.
 * 
 * No final, o prgrama deverá emitir uma das seguintes mensagens:
 * 
 * "sequência inferior a dois elementos"
 * "sequência ordenada estritamente por ordem crescente" 
 * "sequência ordenada estritamente por ordem decrescente"
 * "sequência com elementos repetidos consecutivos"
 * "sequência não ordenada"
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    int last_n = -1, n;    // valores lidos, o anterior e o corrente
    bool equals=false;     // afetado a "true" no caso da ocorrência de elementos repetidos
    bool increasing=true;  // afetado a "false" caso se verifique impossibilidade de sequência crescente
    bool decreasing=true;  // afetado a "false" caso se verifique impossibilidade de sequência decrescente
    int total=0;           // total de valores lidos

    printf("indique uma sequência de inteiros positivos, terminada por 0: ");
    // ler o primeiro valor
    scanf("%d", &n);

    while (n != 0) {
        total++;
        if (last_n != -1) {
            if (n <= last_n) {
                increasing = false;
            }
            if (n >= last_n) {
                decreasing = false;
            }
            if (n == last_n) {
                equals = true;
            }
        }
        last_n = n;
        // ler novo valor
        scanf("%d", &n);
    }
   
    // mostrar os resultados
    if (total < 2) {
        printf("sequência inferior a dois elementos\n");
    }
    else if (increasing) {
        printf("sequência ordenada estritamente por ordem crescente\n");
    }
    else if (decreasing) {
        printf("sequência ordenada estritamente por ordem decrescente\n");
    }
    else if (equals) {
        printf("sequência com elementos repetidos consecutivos\n");
    }
    else {
        printf("sequência não ordenada\n");
    }
    return 0;

}


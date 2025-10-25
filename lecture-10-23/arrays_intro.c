/**
 * Introdução aos arrays na linguagem C
 */

 #include <stdio.h>

#define SIZE1 100


int main() {
    // declaração de um array de 100 inteiros sem iniciação
    int vals1[SIZE1];

    // afectação do 2 elemento do array com o valor 5
    vals1[2] = 5;

    // leitura do 2º elemento do array 
    int v2 = vals1[2];

    printf("vals[2]=%d\n", v2);

    // declaração de um array de 100 inteiros com iniciação 
    // os primeiros 4 elementos do array ficam com os valores indicados
    // os outros 96 ficam com 0.
    int vals2[SIZE1] = { 1,2, 3, 4 };

    // declaração de um array iniciado sem dimensão explícita
    // nas posições de 0 a 11 estão valores que correspodem aos dias dos
    // meses do ano (de janeiro a dezembro). Embora não indicado o array fica com dimensão 12
    int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // podemos saber quantos elementos um array tem se usarmos o operador sizeof
    // o operador sizeof aplicado a variáveis indica o número de bytes ocupadp pela variável
    int month_days_size = sizeof(month_days)/sizeof(int);
    printf("o array month_days tem %d elementos\n", month_days_size);

    // mostrar o conteúdo do array month_days
    printf("month_days = [%d", month_days[0]);
    for(int i=1; i < month_days_size; ++i) {
        printf(", %d", month_days[i]);
    }
    printf("]\n");
    return 0;

}
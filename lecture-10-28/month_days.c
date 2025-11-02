/**
 * Implementação e teste de função que calcula o número de dias de
 * um dado mês num dado ano, usando um array auxiliar
 */

 #include <stdio.h>
 #include <stdbool.h>

 bool leap_year(int year) {
    // os parêntesis na operação "ou" são necessáros
    // pois esta tem menos prioridade do que a operação "e".
    return  year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
 }

 int month_days(int month, int year) {
    // meses:    J    F   M  A   M   J   Jul  A   S  O   N   D
    int md[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // "month" é um valor entre 1 e 12
    int days = md[month -1];

    if (month == 2 && leap_year(year)) {
        days++;
    }
    return days;
 }

 int main() {
    while(true) {
        int m, y;
        printf("mês e ano? ");
        scanf("%d%d", &m, &y);

        // terminar o ciclo se um dos valor for 0
        if (y == 0 || m == 0) {
            break;
        }
        int days = month_days(m, y);

        printf("o mês %d no ano %d tem %d dias!\n",
                m, y, days );
        
    }
    return 0;
 }
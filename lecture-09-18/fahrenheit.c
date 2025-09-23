/**
 * Programa para converter u dado valor em graus fahrenheit 
 * para graus celsius
 * 
 * Autor: Jorge Martins, setembro 2005
 * Build: gcc -o fahrenheit -Wall fahrenheit.c
 */

#include <stdio.h>

int main() {
    double fahren, celsius;
    printf("Introduza o valor em graus fahrenheit: ");

    // recolha do valor em graus fahrenheit
    scanf("%lf", &fahren);

    // conversão para graus celsius
    // notem a necessidade do cast explícito do valor inteiro 5 
    // para double, de modo a garantir que a divisão.
    // Neste caso podíamos ter escrito a divisão como: (5.0/9)
    // Mas se os operandos (numerador e denominador) fossem variáveis
    // teríamos de usar o cast explícito
    // É claro que os parêntesis a embrulhar a divisão não são aqui
    // estritamente necessários, foram colocados para chamar a atenção
    // da diferença entre divisão real e divisão inteira
    celsius = (fahren - 32)*( (double) 5/9);

    // apresentação do resultado da conversão com 3 casas decimais
    printf("O valor em graus celsius é: %.3lf\n", celsius);

    return 0;
}

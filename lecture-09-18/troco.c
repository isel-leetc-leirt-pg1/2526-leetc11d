
/**
 * Este programa apresenta o número mínima de moedas 
 * (de 2 euros, 1 euro, 50 cent, 20 cent, 10 cent, 5 cent, 2 cent e 1 cent)
 * que correspondem à entrega de um valor de troco em cêntimos recolhido
 * do terminal
 * 
 * Autor: Jorge Martins
 * Build: gcc -o troco -Wall troco.c
 */

 #include <stdio.h>

 int main() {
    int troco;   // valor do troco
    int nmoedas; // total de moedas de um dado valor

    printf("Introduza o valor do troco em cêntimos: ");
    scanf("%d", &troco);

    printf("O troco de %d cêntimos é entregue com o conjunto de moedas:\n", troco);
    
    // moedas de 2 euros
    nmoedas = troco / 200;
    troco = troco % 200; // O resto do troco (tirando as moedas de 2 euros) corresponde
                         // ao resto da divisão por 200
    printf("\t%d moeda)s de 2 euros\n", nmoedas);

    // moedas de 1 euro
    nmoedas = troco / 100;
    troco = troco % 100; // O resto do troco (tirando as moedas de 1 euros) corresponde
                         // ao resto da divisão por 100
    printf("\t%d moeda)s de 1 euro\n", nmoedas);

    // moedas de 50 cêntimos
    nmoedas = troco / 50;
    troco = troco % 50; // O resto do troco (tirando as moedas de 50 cêntimos) corresponde
                         // ao resto da divisão por 50
    printf("\t%d moeda)s de 50 cêntimos\n", nmoedas);

    // moedas de 20 cêntimos
    nmoedas = troco / 20;
    troco = troco % 20; // O resto do troco (tirando as moedas de 20 cêntimos) corresponde
                         // ao resto da divisão por 20 
    printf("\t%d moeda)s de 20 cêntimos\n", nmoedas);

    // moedas de 10 cêntimos
    nmoedas = troco / 10;
    troco = troco % 10; // O resto do troco (tirando as moedas de 10 cêntimos) corresponde
                         // ao resto da divisão por 10 
    printf("\t%d moeda)s de 10 cêntimos\n", nmoedas);

    // moedas de 5 cêntimos
    nmoedas = troco / 5;
    troco = troco % 5; // O resto do troco (tirando as moedas de 5 cêntimos) corresponde
                         // ao resto da divisão por 5 
    printf("\t%d moeda)s de 5 cêntimos\n", nmoedas);

     // moedas de 2 cêntimos
    nmoedas = troco / 2;
    troco = troco % 2; // O resto do troco (tirando as moedas de 2 cêntimos) corresponde
                       // ao resto da divisão por 2
    printf("\t%d moedas de 2 cêntimos\n", nmoedas);

    // o resto do troco só pode ser 0 ou 1 pois é o resultado do reasto da divisão por 2
    printf("\t%d moedas de 1 cêntimo\n", troco);

    return 0;
 }
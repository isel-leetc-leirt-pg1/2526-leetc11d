#include <stdio.h>

/**
 * Esta função calcula e retorna o dígito de verificação
 * para o número do cartão de cidadão recebido por parâmetro
 * 
 */
int cc_verify(int cc) {
    int sum_pesos = 0, peso = 2;

    while ( cc > 0) {
        sum_pesos = sum_pesos + (cc % 10) * peso;
        peso = peso + 1;
        cc = cc / 10;
    }

    return 11 - sum_pesos % 11;
}

int main() {
    int cc;

    printf("Indique o número do cc: ");
    scanf("%d", &cc);

    int dv = cc_verify(cc);
    
    // executem o programa com o vosso número de CC e verifiquem se o digito bate certo
    printf("O dígito de verificação do cc nº %d é %d\n", cc, dv);
    return 0;
}

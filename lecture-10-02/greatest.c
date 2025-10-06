#include <stdio.h>

int max(int v1, int v2);

/**
 * Primeira função para calcular o maior de três valores inteiros.
 * usando um algoritmo que verifica todas as possibilidades.
 */
int max3a(int a, int b, int c) {
	if (a > b) {
		if (a > c) {
			return a;
		}
		else {
			return b;
		}
	}
	else {
		if (b > c) {
			return b;
		}
		else {
			return c;
		}
	}
}

/**
 * Segunda função para calcular o maior de três valores inteiros.
 * Neste caso assume-se que "a" é o maior (greatest).
 * Vai-se comparando greatest com os restantes, substituindo greatest se necessário
 */
int max3b(int a, int b, int c) {
	int greatest = a;
	if ( b > greatest) {
		greatest = b;
	}
	if ( c > greatest) {
		greatest = c;
	}
	return greatest;
}

/**
 * Terceira função para calcular o maior de três valores inteiros.
 * Neste caso tira-se partido da função max, que retorna o maior de 2
 * valores inteiros
 */
int max3c(int a, int b, int c) {
	return max(max(a,b), c);
}

int main() {
    printf("max(3,5)=%d\n", max(3,5));
    
    printf("max3a(3,8,5)=%d\n", max3a(3, 8, 5));
    
    printf("max3b(3,8,5)=%d\n", max3b(3, 8, 5));
    
    printf("max3c(3,8,5)=%d\n", max3c(3, 8, 5));
    
    return 0;
}

int max(int v1, int v2) {
    if (v1 > v2) {
        return v1;
    }
    else {
        return v2;
    }
}


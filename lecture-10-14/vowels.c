/**
 * Conta as vogais de uma linha lida do input
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>



bool is_vowel(char c) {
    c = tolower(c);
    
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


int main() {
    int nvowels = 0;
    char c;

    printf("linha? ");
    
    do {
        c = getchar();
        if (is_vowel(c)) {
            nvowels++;
        }
    }
    while(c != '\n');
    printf("foram lidas %d vogais\n", nvowels);
    return 0;
}
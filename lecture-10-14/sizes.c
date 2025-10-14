#include <stdio.h>

int main() {
    printf("sizeof(char)=%ld\n", sizeof(char));
    printf("sizeof(short)=%ld\n", sizeof(short));
    printf("sizeof(int)=%ld\n", sizeof(int));
    printf("sizeof(long)=%ld\n", sizeof(long));

    printf("sizeof(float)=%ld\n", sizeof(float));
    printf("sizeof(double)=%ld\n", sizeof(double));


    printf("unsigned types:\n");

    printf("sizeof(unsigned char)=%ld\n", sizeof(unsigned char));
    printf("sizeof(unsigned short)=%ld\n", sizeof(unsigned short));
    printf("sizeof(unsigned int)=%ld\n", sizeof(unsigned int));
    printf("sizeof(unsigned long)=%ld\n", sizeof(unsigned long));


    unsigned short s1 = 20000, s2 = 50000;
    unsigned short res = s1 + s2;
    printf("%u + %u = %u", s1, s2, res);

    return 0;
}
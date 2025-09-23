#include <stdio.h>

int main() {
    double ref_fahren = 86.3, celsius;
    celsius = (ref_fahren - 32)*5/9;

    printf("%lf fahrenheit correspodem a %lf celsius\n",
        ref_fahren, celsius);
    return 0;
}

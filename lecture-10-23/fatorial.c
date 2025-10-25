long fatorial(int n) {
    if (n == 0) return 1;
    return n* fatorial(n-1);
}


int main() {
    int val;

    printf("val? ");
    scanf("%d", &val);

    long f = fatorial(val);
    printf("%d! = %ld\n", val, f);
    return 0;
}
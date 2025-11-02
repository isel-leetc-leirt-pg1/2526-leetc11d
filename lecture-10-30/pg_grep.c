

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool pg_getline(char line[], int maxline) {
    if (fgets(line, maxline, stdin) == NULL) return false;
    return true;
}

int main() {
    char tofind[] = "needle";
    char line[256];
    int nline = 0;

    while(pg_getline(line, 256) == true) {
        //printf("%s", line);
        nline++;
        if (strstr(line, tofind) != NULL) {
            printf("%d: %s", nline, line);
        }
    }
    return 0;
}
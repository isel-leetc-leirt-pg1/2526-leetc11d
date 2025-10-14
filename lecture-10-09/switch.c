#include <stdio.h>
#include <stdbool.h>

bool leap_year(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int month_days(int month, int year) {
    int ndays;

    switch(month) {
        case 2: {
            if (leap_year(year)) {
                ndays = 29;
            }
            else {
                ndays = 28;
            }
            break;
        }
        case 4: case 6: case 9: case 11 : {
            ndays = 30;
            break;
        }

        default: {
            ndays = 31;
            break;
        }

    }
    return ndays;
}

int main() {
    int nd, m, y;

    printf("mês e ano ? ");
    scanf("%d%d", &m, &y);

    if (m < 0 || m > 12 || y < 1600) {
        printf("mês ou ano inválido(s)!\n");
        return 1;
    }
    
    nd = month_days(m, y);
    printf("dias do mês %d: %d\n", m, nd);
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

#define SIDE 4

typedef  int matrix_t[SIDE][SIDE];

bool is_upper_triangular(matrix_t m) {
    for(int i=0; i < SIDE; ++i) {
        for(int j=0; j < i; j++) {
            if (m[i][j] != 0) 
                return false;
        }
    }
    return true;
}

bool is_lower_triangular(matrix_t m) {
    for(int i=0; i < SIDE; ++i) {
        for(int j=i+1; j < SIDE; j++) {
            if (m[i][j] != 0) 
                return false;
        }
    }
    return true;
}

bool is_pascal_triangle(matrix_t m) {
    // check first line
    for(int i=0; i < SIDE; ++i) {
        if (m[0][i] != 1) 
            return false;
    }
     // check first column
    for(int i=0; i < SIDE; ++i) {
        if (m[i][0] != 1) 
            return false;
    }

    // check remain cells
    for(int i=1; i < SIDE; ++i) {
        for(int j=1; j < SIDE; j++) {
            if (m[i][j-1] + m[i-1][j] != m[i][j]) 
                return false;
        }
    }
    return true;
}



int main() {
    matrix_t m1 = {
        {1, 2, 3, 4},
        {0, 1, 3, 5},
        {0, 0, 7, 1},
        {0, 0, 1, 2}
    };

    matrix_t m2 = {
        {1, 2, 0, 0},
        {0, 1, 0, 0},
        {4, 0, 7, 0},
        {0, 0, 1, 2}
    };

     matrix_t m3 = {
        {1, 1, 1, 1},
        {1, 2, 3, 4},
        {1, 3, 6, 10},
        {1, 4, 10, 21}
    };

    printf("is_upper_triangular(m1)=%s\n",
        is_upper_triangular(m1) ? "true" : "false");
    printf("is_lower_triangular(m2)=%d\n",
        is_lower_triangular(m2) );

    printf("is_pascal_triangle(m3)=%d\n",
        is_pascal_triangle(m3) );
 
    return 0;
       
}



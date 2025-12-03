#include <pg/pglib.h>


#define BOARD_SIDE 8

typedef enum { BLACK, WHITE, NONE } piece_t;

typedef struct cell {
    piece_t piece;
    RGB clr;
    int x, y; 
} cell_t;


typedef struct board {
    cell_t cells[BOARD_SIDE][BOARD_SIDE];
} board_t;



void board_init(board_t *board) {
    
}
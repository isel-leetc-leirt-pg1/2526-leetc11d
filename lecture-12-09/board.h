#include <pg/pglib.h>

#define BOARD_ROWS 8
#define BOARD_COLS BOARD_ROWS

typedef enum { NO_PIECE, BLACK_PIECE, WHITE_PIECE } piece_t;

typedef struct cell {
    piece_t piece;
    int col, row; 
} cell_t;

typedef struct {
    cell_t cells[BOARD_ROWS][BOARD_COLS];
    int nblacks, nwhites;

} board_t;

void board_init(board_t *board);
bool b_cell(int r, int c);


    
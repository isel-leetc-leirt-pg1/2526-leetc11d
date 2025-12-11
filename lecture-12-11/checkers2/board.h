#include <pg/pglib.h>

#define BOARD_NLINES 8
#define BOARD_NCOLS 8

typedef enum { BLACK_PIECE, WHITE_PIECE, NONE_PIECE } piece_t;

typedef struct cell {
    piece_t piece;
    int col, line; 
} cell_t;

typedef struct {
    cell_t cells[BOARD_NLINES][BOARD_NCOLS];
    int nblacks, nwhites;
} board_t;

void board_init(board_t *board);
void board_show(board_t *board);
piece_t board_piece_at(board_t *board, int r, int c);
bool legal_piece_pos(int r, int c);
bool game_play(board_t *board, int r1, int c1, int r2, int c2);
    
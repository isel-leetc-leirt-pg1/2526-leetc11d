#include "board.h"


bool b_cell(int r, int c) {
    return (r + c) % 2 == 0;
}

void cell_init(cell_t *c, piece_t p, int row, int col) {
    c->piece = p;
    c->row = row;
    c->col = col;
}

void board_init(board_t *board) {
    for (int r = 0; r < 3; ++r) {
        for(int c = 0; c < BOARD_COLS; ++c) {
            piece_t piece;
            if (b_cell(r,c)) {
                piece = BLACK_PIECE;
            }
            else {
                piece = NO_PIECE;
            }
            cell_init(&board->cells[r][c], piece, r, c);
        }
    }
    // A Completar!

}
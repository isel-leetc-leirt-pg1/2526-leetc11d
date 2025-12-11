#include "board.h"


// check if it is a black cell
bool b_cell(int r, int c) {
    return (r + c) % 2 == 0;
}

void cell_init(cell_t *c, piece_t p, int row, int col) {
    c->piece = p;
    c->row = row;
    c->col = col;
}

void board_rows_with_pieces(board_t *board, int start, int end, piece_t p) {
    for (int r = start; r < end; ++r) {
        for(int c = 0; c < BOARD_COLS; ++c) {
            piece_t piece;
            if (b_cell(r,c)) {
                piece = p;
            }
            else {
                piece = NO_PIECE;
            }
            cell_init(&board->cells[r][c], piece, r, c);
        }
    }
}

void board_init(board_t *board) {
    // três primeiras linhas
    board_rows_with_pieces(board, 0, 3, BLACK_PIECE);
    // as duas linhas do meio
    for(int r = 3; r < 5; ++r) {
        for (int c = 0; c < BOARD_COLS; ++c) {
            cell_init(&board->cells[r][c], NO_PIECE, r, c);
        }
    }
    
    // três últimas linhas
    board_rows_with_pieces(board, 5, BOARD_ROWS, WHITE_PIECE);
}
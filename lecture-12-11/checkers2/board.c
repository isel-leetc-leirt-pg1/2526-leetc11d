
#include <stdio.h>
#include "board.h"

// globals


/**
 * Iniciação de uma célula
 */
void cell_init(cell_t *c, piece_t p, int row, int col) {
    c->piece = p;
    c->line = row;
    c->col = col;
}

/**
 * Apresenta na consola de texto
 * o estado do tabuleiro
 * Usada para efeitos de debug
 */
void board_show(board_t *board) {
    for(int l = 0; l < BOARD_NLINES; ++l) {
        for(int c = 0; c < BOARD_NCOLS; ++c) {
             char p;
             piece_t piece = board->cells[l][c].piece;

             if (piece == WHITE_PIECE) p = 'W';
             else if (piece == BLACK_PIECE) p = 'B';
             else p = 'N';
             printf("%c(%d,%d) ", p, board->cells[l][c].line, board->cells[l][c].col);
        }  
        printf("\n\n");   
    }
}

/**
 * inicia áreas do tabuleiro com peças
 */
void board_init_pieces_area(board_t *board, int start, int end, piece_t piece) {
   for(int l = start; l < end; ++l) {
        for(int c = 0; c < BOARD_NCOLS; ++c) {
            if ((l+c) %2 == 0) {
                cell_init(&board->cells[l][c], piece, l,c );
            }
            else {
                cell_init(&board->cells[l][c], NONE_PIECE, l,c);
            }
        }     
    }
}

/**
 * Inicia o tabuleiro de jogo
 */
void board_init(board_t *board) {
    printf("board init start\n");

    board_init_pieces_area(board, 0, 3, WHITE_PIECE);
  
    printf("board step 1\n");

    for(int l = 3; l < 5; ++l) {
        for(int c = 0; c < BOARD_NCOLS; ++c) {
            cell_init(&board->cells[l][c], NONE_PIECE, l,c ); 
        }     
    }
    
    printf("board step 2\n");

    board_init_pieces_area(board, 5, 8, BLACK_PIECE);
  
    printf("board init done\n");

}

/**
 * retorna a peça presente na casa indicada
 */
piece_t board_piece_at(board_t *board, int r, int c) {
    return board->cells[r][c].piece;
}

/**
 * Indica se se trata de uma preta (onde pode haver uma peça)
 */
bool legal_piece_pos(int r, int c) {
    // printf("r=%d, c=%d\n", r, c);
    return (r +c) % 2 == 0;
}


/**
 * Movimento dimplificado de uma peça
 */
bool game_play(board_t *board, int r1, int c1, int r2, int c2) {
    piece_t p1 = board_piece_at(board, r1,c1);
    if (p1 == NONE_PIECE) return false;
    piece_t p2 = board_piece_at(board, r2,c2);
    if (!legal_piece_pos(r2, c2) || p2 != NONE_PIECE) return false;

    board->cells[r2][c2].piece = p1;
    board->cells[r1][c1].piece = NONE_PIECE;
    return true;
}



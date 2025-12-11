#include "board.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 900

#define TOP_BOARD 100

#define CELL_SIDE 80
#define BOARD_NCELLS 8
#define BOARD_SIDE (CELL_SIDE*BOARD_NCELLS)
 

#define COLOR_ODD graph_rgb(245, 245, 240)
#define COLOR_EVEN  c_dgray


#define BLACK_PIECE_CLR c_black
#define WHITE_PIECE_CLR graph_rgb(190, 190, 170)


#define BACK_COLOR graph_rgb(0,96,0)


// game state

int board_x, board_y; // posição do tabuleiro na janela
board_t board;
int old_col = -1, old_row = -1; // auxiliares para a realização de um movimento de peça

// components

#define SHOW_COORDS_X 20
#define SHOW_COORDS_Y 20

MsgView pressed_coords;


/**
 * Inicia componentes de apresentação
 * Neste caso só MsgView que apresenta as coordenadas da jogada
 */
void init_components() {
    mv_create(&pressed_coords, SHOW_COORDS_X, SHOW_COORDS_Y, 3, LARGE_FONT, c_orange, c_dgray );
    mv_show_text(&pressed_coords, "   ", ALIGN_CENTER);
}

/**
 * Converte coordenadas de tabuleiro em coordenadas de ecrâ
 */
void board_to_screen_coords(int r, int c, int *sx, int *sy) {
    *sx = board_x + c*CELL_SIDE;
    *sy = board_y + BOARD_SIDE - (r +1)*CELL_SIDE;
}

/**
 * Converte coordenadas de ecrâ  em coordenadas de ecrâ tabuleiro
 */
bool screen_coords_to_board(int sx, int sy, int *bcol, int *bline) {
    if (sx < board_x || sx > board_x + BOARD_SIDE || sy < board_y || sy >= board_y + BOARD_SIDE) {
        return false;
    }
    *bcol = (sx - board_x)/CELL_SIDE;
    *bline = 7 - (sy - board_y)/CELL_SIDE;
    return true;
}


/**
 * desenha uma célula (casao tabuleiro com a respectiva peça, a existir)
 */
void cell_draw(cell_t *c) {
    int sx, sy;
    board_to_screen_coords(c->line, c->col, &sx, &sy);
    RGB clr = (c->line+c->col) % 2 == 0 ? COLOR_EVEN : COLOR_ODD;
    graph_rect(sx,sy, CELL_SIDE, CELL_SIDE, clr, true);
    if (c->piece == NONE_PIECE) return;
    RGB piece_clr = (c->piece == BLACK_PIECE) ? BLACK_PIECE_CLR : WHITE_PIECE_CLR;
    graph_circle(sx + CELL_SIDE/2, sy + CELL_SIDE/2, CELL_SIDE/2 - 10, piece_clr, true);
    RGB inner_circle;
    inner_circle = c->piece == BLACK_PIECE ? graph_rgb(128,128,128) : c_black;
    graph_circle(sx + CELL_SIDE/2, sy + CELL_SIDE/2, CELL_SIDE/2- 20, inner_circle, false);

}

/**
 * desenha o tabuleiro de jogo
 */
void draw_board() {
      
    int x = board_x;
    int y = board_y;

    for(int r =0; r < BOARD_NCELLS; ++r) {
       for(int c =0; c < BOARD_NCELLS; ++c) {
            cell_draw(&board.cells[r][c]);
       }
    }
    graph_rect(0, TOP_BOARD, WINDOW_WIDTH, 10, c_black, true);
    graph_rect(board_x, board_y, BOARD_SIDE, BOARD_SIDE, c_black, false);

    // draw cell coords
    Size fs = graph_font_size(LARGE_FONT);
    x = board_x + (CELL_SIDE- fs.width)/2;
    y = board_y + BOARD_SIDE + fs.height+4;
    for(int i=0; i < BOARD_NCELLS; ++i) {
        char text[2] = { 'A' + i };
        graph_text2(x, y, c_white, BACK_COLOR, text, LARGE_FONT);
        x += CELL_SIDE;
    }

    x = board_x - fs.width - 4;
    y = board_y + (CELL_SIDE - fs.height)/2 + fs.height;
    for(int i=0; i < BOARD_NCELLS; ++i) {
        char text[2] = { '8' - i };
        graph_text2(x, y, c_white, BACK_COLOR, text, LARGE_FONT);
        y += CELL_SIDE;
    }


}

/**
 * lógica de realização da jogada
 */
void process_play(int row, int col) {
    if (legal_piece_pos(row,col)) {
        if (old_col != -1) {
            if (game_play(&board, old_row, old_col, row, col)) {
                cell_draw(&board.cells[old_row][old_col]);
                cell_draw(&board.cells[row][col]);
            } 
            old_col = -1;
            old_row = -1;
        }
        else {
            if (board_piece_at(&board, row,col) != NONE_PIECE) {
                old_col = col;
                old_row = row;
            }
        }
    }
}

void mouse_handler(MouseEvent me) {
    if (me.type == MOUSE_BUTTON_EVENT && me.state == BUTTON_PRESSED && me.button == BUTTON_LEFT) {
        int bcol, brow;
        if (screen_coords_to_board(me.x, me.y, &bcol, &brow)) {
            char coords[4] = { 'A'+ bcol, ':', '1' + brow};
            mv_show_text(&pressed_coords, coords, ALIGN_CENTER);
            process_play(brow, bcol);
        }
    }
}

/**
 * Inicia o estado do jogo e sua apresentação
 */
void init_state() {
    board_x = (WINDOW_WIDTH - BOARD_SIDE)/2;
    board_y = TOP_BOARD + (WINDOW_HEIGHT - TOP_BOARD -  BOARD_SIDE)/2;
    board_init(&board);
}

int main() {
    graph_init2("Checkers", WINDOW_WIDTH, WINDOW_HEIGHT);

    // draw background
    graph_rect(0,0, WINDOW_WIDTH, WINDOW_HEIGHT, BACK_COLOR, true);

    init_state();
    init_components();
    draw_board();

    // mostra na consola detexto o estdo do tabuleiro
    board_show(&board);

    graph_regist_mouse_handler(mouse_handler);
    graph_start();
}

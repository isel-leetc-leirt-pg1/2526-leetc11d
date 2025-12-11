/**
 * Construção de uma versão básica do jogo das damas
 * Comando para gerar o executável:
 *      gcc -o checkers -Wall checkers.c board.c -lpg
 * 
 * Esta versão está no estado em que ficou no final da aula
 * e está a desenhar incorretamente o tabuleiro.
 * É um exercício educativo entarem resolver o problema
 */

#include <pg/pglib.h>
#include "board.h"

// dimensões da janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 900

// tamanho em pixels do lado das "casas" do tabuleiro
#define CELL_SIDE 80

// tameanho em pixels dos lados do tabuleiro
#define BOARD_SIDE (CELL_SIDE*BOARD_COLS)

// limite superior do tabuleiro
#define TOP_BOARD 100

// cores do tabuleiro

#define BLACK_CELL_CLR c_black
#define WHITE_CELL_CLR c_white

#define LEGEND_CLR c_black
#define BACKGROUND_CLR c_white
#define LEGEND_GAP 5


// cores das peças
#define WHITE_PIECE_CLR c_white
#define BLACK_PIECE_CLR c_gray

#define WHITE_PIECE_CLR_ALT graph_rgb(240, 240, 200)
#define BLACK_PIECE_CLR_ALT graph_rgb(164, 128, 64)

// divisão entre informações de jogo e tabuleiro
#define FRAME_CLR c_black
#define SEP_HEIGHT 10


// componentes

#define SHOW_COORDS_Y 30
#define SHOW_COORDS_X 100

#define BT_CHG_X    600
#define BT_CHG_Y    30

#define CT_CHANGES_X 300
#define CT_CHANGES_Y 30

// variáveis globais

// componentes de interação
MsgView show_coords;
Button bt_chg_clrs;
Counter ct_clr_changes;


int clr_changes_count;
int board_x, board_y;
int black_piece_clr, white_piece_clr;

board_t board; // tabuleiro do jogo


/**
 * Converte coordenadas de ecrâ em coordenadas de tabuleiro
 * Retorna true se a conversão foi bem sucedida 
 * (colocada nos inteiros apontados por "brow" e "bcol")
 * ou false, se o tabuleiro não foi selecionado
 */
bool screen_coords_to_board(int sx, int sy, int *brow, int *bcol) {
    if (sx >= board_x && sx < board_x + BOARD_SIDE &&
         sy >= board_y && sy < board_y + BOARD_SIDE) {
        *bcol = (sx - board_x) / CELL_SIDE;
        *brow = 7 - (sy - board_y)/CELL_SIDE;
        return true;

    }
    return false;
}

void board_to_screen_coords(int row, int col, int *sx, int *sy)  {
   // A completar
   *sx = board_x + col * CELL_SIDE;
   *sy = board_y + BOARD_SIDE - CELL_SIDE*(row +1);
}

void cell_draw(cell_t *cell) {
    int sx, sy;
    board_to_screen_coords(cell->row, cell->col, &sx, &sy );
    
    RGB clr;
    /*
    if (b_cell(cell->row, cell->col)) {
        clr = BLACK_CELL_CLR;
    }
    else {
        clr = WHITE_CELL_CLR;
    }
        */
    clr = b_cell(cell->row, cell->col) ? BLACK_CELL_CLR : WHITE_CELL_CLR; 


    graph_rect(sx, sy, CELL_SIDE, CELL_SIDE, clr, true);
    if (cell->piece != NO_PIECE) {
        RGB piece_color;
        piece_color = 
          (cell->piece == BLACK_PIECE) ? black_piece_clr : white_piece_clr;
        
        graph_circle(sx + CELL_SIDE/2, sy + CELL_SIDE/2, CELL_SIDE/3,
           piece_color, true);
    }

    // a completar
}

/**
 * Constrói e apresenta os componentes de informação sobre o jogo
 */
void init_components() {
    // message view
    mv_create(&show_coords,SHOW_COORDS_X, SHOW_COORDS_Y,6, LARGE_FONT, c_orange, c_dgray); 
    mv_show_text(&show_coords, "   ", ALIGN_CENTER);

    // button
    bt_create(&bt_chg_clrs, BT_CHG_X, BT_CHG_Y, "Change Colors", c_orange);
    bt_draw(&bt_chg_clrs, BUTTON_RELEASED);
    // counter
    ct_create(&ct_clr_changes, CT_CHANGES_X, CT_CHANGES_Y, 0, "Changes Count", MEDIUM_FONT);
    ct_show(&ct_clr_changes);
}

void change_colors() {
    if (black_piece_clr == BLACK_PIECE_CLR) {
        black_piece_clr = BLACK_PIECE_CLR_ALT;
        white_piece_clr = WHITE_PIECE_CLR_ALT;
    }
    else {
        black_piece_clr = BLACK_PIECE_CLR;
        white_piece_clr = WHITE_PIECE_CLR;
    }
}



/**
 * Versão preliminar do desendo do tabuleiro
 */
void draw_board0() {

    graph_rect(0, TOP_BOARD, WINDOW_WIDTH, SEP_HEIGHT, FRAME_CLR, true);
    board_x = (WINDOW_WIDTH - BOARD_SIDE)/2;
    board_y = (WINDOW_HEIGHT - TOP_BOARD - BOARD_SIDE)/2 + TOP_BOARD;

    int x = board_x;
    int y = board_y;

    for(int l = 0; l < BOARD_ROWS; l++) {
        x = board_x;
        for (int c = 0; c < BOARD_COLS; c++) {
            RGB clr;
            if ((l+c) % 2 == 0) {
                clr = BLACK_CELL_CLR;
            }
            else {
                clr = WHITE_CELL_CLR;
            }
            graph_rect(x, y, CELL_SIDE, CELL_SIDE, clr, true);
            x += CELL_SIDE;
        }
        y += CELL_SIDE;
      
    }
    graph_rect(board_x, board_y, BOARD_SIDE, BOARD_SIDE, FRAME_CLR, false);

    // draw letters
    int ty, tx;

    Size fs = graph_font_size(LARGE_FONT);
    ty = board_y + BOARD_SIDE + fs.height + LEGEND_GAP;
    tx = board_x + CELL_SIDE/2;

    for(int c = 0; c < BOARD_COLS; ++c) {
        char text[] = { 'A' + c, 0};

       
        graph_text2(tx, ty, LEGEND_CLR, BACKGROUND_CLR, text, LARGE_FONT );
        tx += CELL_SIDE;
    }

    ty = board_y + CELL_SIDE/2 + fs.height;
    tx = board_x  - fs.width - LEGEND_GAP;

    for(int l = 0; l < BOARD_ROWS; ++l) {
        char text[] = { '8' - l, 0};

       
        graph_text2(tx, ty, LEGEND_CLR, BACKGROUND_CLR, text, LARGE_FONT );
        ty += CELL_SIDE;
    }
}

void draw_board() {

    graph_rect(0, TOP_BOARD, WINDOW_WIDTH, SEP_HEIGHT, FRAME_CLR, true);
    board_x = (WINDOW_WIDTH - BOARD_SIDE)/2;
    board_y = (WINDOW_HEIGHT - TOP_BOARD - BOARD_SIDE)/2 + TOP_BOARD;
 
    for(int l = 0; l < BOARD_ROWS; l++) {
        for (int c = 0; c < BOARD_COLS; c++) {
             cell_draw(&board.cells[l][c]);
        }
    }

    // draw letters
    int ty, tx;

    Size fs = graph_font_size(LARGE_FONT);
    ty = board_y + BOARD_SIDE + fs.height + LEGEND_GAP;
    tx = board_x + CELL_SIDE/2;

    for(int c = 0; c < BOARD_COLS; ++c) {
        char text[] = { 'A' + c, 0};

        graph_text2(tx, ty, LEGEND_CLR, BACKGROUND_CLR, text, LARGE_FONT );
        tx += CELL_SIDE;
    }


    graph_rect(board_x, board_y, BOARD_SIDE, BOARD_SIDE, FRAME_CLR, false);


    ty = board_y + CELL_SIDE/2 + fs.height;
    tx = board_x  - fs.width - LEGEND_GAP;

    for(int l = 0; l < BOARD_ROWS; ++l) {
        char text[] = { '8' - l, 0};

        graph_text2(tx, ty, LEGEND_CLR, BACKGROUND_CLR, text, LARGE_FONT );
        ty += CELL_SIDE;
    }
}

void init_state() {
    black_piece_clr = BLACK_PIECE_CLR;
    white_piece_clr = WHITE_PIECE_CLR;
}

bool process_components(int x, int y, int state) {
    if (bt_selected(&bt_chg_clrs, x, y)) {
        bt_draw(&bt_chg_clrs, state);
        if (state == BUTTON_RELEASED) {
            change_colors();
            draw_board();
            ct_inc(&ct_clr_changes);
            ct_show(&ct_clr_changes);
            clr_changes_count++;
        }
        return true;
    }
    return false;
}


/**
 * Função que trata dos eventos de rato
 */
void mouse_handler(MouseEvent me) {

    if (me.type == MOUSE_BUTTON_EVENT  &&
         me.button == BUTTON_LEFT) {
        if (process_components(me.x, me.y, me.state)) {
            return;
        }

        if (me.state == BUTTON_PRESSED) {
            int row, col;
            if (screen_coords_to_board(me.x, me.y, &row, &col)) {
                char coords[] = { 'A' + col, ':' , '1' + row, 0 };
                mv_show_text(&show_coords, coords, ALIGN_CENTER);
            }
        }

    }
}

int main() {
    graph_init2("Checkers", WINDOW_WIDTH, WINDOW_HEIGHT);
    init_state();

    init_components();

    board_init(&board);

    draw_board();

    graph_regist_mouse_handler(mouse_handler);
    graph_start();
}


/**
 * Construção de uma versão básica do jogo das damas
 * Comando para gerar o executável:
 *      gcc -o checkers -Wall checkers.c board.c -lpg
 */

#include <pg/pglib.h>

// dimensões da janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 900

// tamanho em pixels do lado das "casas" do tabuleiro
#define CELL_SIDE 80

// linhas e colunas do tabuleiro
#define BOARD_COLS 8
#define BOARD_ROWS BOARD_COLS

// tameanho em pixels dos lados do tabuleiro
#define BOARD_SIDE (CELL_SIDE*BOARD_COLS)

// limite superior do tabuleiro
#define TOP_BOARD 100

// cores do tabuleiro

#define EVEN_CLR c_black
#define ODD_CLR c_white
#define LEGEND_CLR c_black
#define BACKGROUND_CLR c_white
#define LEGEND_GAP 5


// divisão entre informações de jogo e tabuleiro
#define FRAME_CLR c_black
#define SEP_HEIGHT 10


// componentes

#define SHOW_COORDS_Y 30
#define SHOW_COORDS_X 100


// variáveis globais

int board_x, board_y;
MsgView show_coords;

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

/**
 * Constrói e apresenta os componentes de informação sobre o jogo
 */
void init_components() {
    mv_create(&show_coords,SHOW_COORDS_X, SHOW_COORDS_Y,6, LARGE_FONT, c_orange, c_dgray); 

    mv_show_text(&show_coords, "   ", ALIGN_CENTER);
}


/**
 * Função que trata dos eventos de rato
 */
void mouse_handler(MouseEvent me) {

    if (me.type == MOUSE_BUTTON_EVENT && me.state == BUTTON_PRESSED &&
         me.button == BUTTON_LEFT) {
        
        int row, col;
        if (screen_coords_to_board(me.x, me.y, &row, &col)) {
            char coords[] = { 'A' + col, ':' , '1' + row, 0 };
            mv_show_text(&show_coords, coords, ALIGN_CENTER);
        }

    }
}

/**
 * Versão preliminar do desendo do tabuleiro
 */
void draw_board() {

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
                clr = EVEN_CLR;
            }
            else {
                clr = ODD_CLR;
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

int main() {
    graph_init2("Checkers", WINDOW_WIDTH, WINDOW_HEIGHT);
    init_components();
    draw_board();

    graph_regist_mouse_handler(mouse_handler);
    graph_start();
}


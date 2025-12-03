#include <pg/pglib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 900

#define CELL_SIDE 80

#define BOARD_CELLS_X 8
#define BOARD_CELLS_Y BOARD_CELLS_X

#define BOARD_SIDE (CELL_SIDE*BOARD_CELLS_X)

#define TOP_BOARD 100

#define EVEN_CLR c_black;
#define ODD_CLR c_white;
#define FRAME_CLR c_black
#define LEGEND_CLR c_black

#define BACKGROUND_CLR c_white
#define LEGEND_GAP 5

#define SEP_HEIGHT 10


// componentes

#define SHOW_COORDS_Y 30
#define SHOW_COORDS_X 100


int board_x, board_y;
MsgView show_coords;


bool screen_coords_to_board(int sx, int sy, int *bline, int *bcol) {
    if (sx >= board_x && sx < board_x + BOARD_SIDE &&
         sy >= board_y && sy < board_y + BOARD_SIDE) {
        *bcol = (sx - board_x) / CELL_SIDE;
        *bline = (sy - board_y)/CELL_SIDE;
        return true;

    }
    return false;
}
void init_components() {
    mv_create(&show_coords,SHOW_COORDS_X, SHOW_COORDS_Y,6, LARGE_FONT, c_orange, c_dgray); 

    mv_show_text(&show_coords, "   ", ALIGN_CENTER);
}


void mouse_handler(MouseEvent me) {

    if (me.type == MOUSE_BUTTON_EVENT && me.state == BUTTON_PRESSED &&
         me.button == BUTTON_LEFT) {

    }
}
void draw_board() {

    graph_rect(0, TOP_BOARD, WINDOW_WIDTH, SEP_HEIGHT, FRAME_CLR, true);
    board_x = (WINDOW_WIDTH - BOARD_SIDE)/2;
    board_y = (WINDOW_HEIGHT - TOP_BOARD - BOARD_SIDE)/2 + TOP_BOARD;

    int x = board_x;
    int y = board_y;

    
    for(int l = 0; l < BOARD_CELLS_Y; l++) {
        x = board_x;
        for (int c = 0; c < BOARD_CELLS_X; c++) {
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

    for(int c = 0; c < BOARD_CELLS_X; ++c) {
        char text[] = { 'A' + c, 0};

       
        graph_text2(tx, ty, LEGEND_CLR, BACKGROUND_CLR, text, LARGE_FONT );
        tx += CELL_SIDE;
    }

    ty = board_y + CELL_SIDE/2 + fs.height;
    tx = board_x  - fs.width - LEGEND_GAP;

    for(int l = 0; l < BOARD_CELLS_X; ++l) {
        char text[] = { '8' - l, 0};

       
        graph_text2(tx, ty, LEGEND_CLR, BACKGROUND_CLR, text, LARGE_FONT );
        ty += CELL_SIDE;
    }
   
}

int main() {
    graph_init2("Checkers", WINDOW_WIDTH, WINDOW_HEIGHT);
    init_components();
    draw_board();
    graph_start();
}


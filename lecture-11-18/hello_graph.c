#include <pg/pglib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define SQUARE_SIDE 200


int main() {
    graph_init2("Hello", WINDOW_WIDTH, WINDOW_HEIGHT);

    graph_rect(0,0,WINDOW_WIDTH, WINDOW_HEIGHT, c_blue, true);

    // desenhar quadrado verde, de lado 200, centrado no ecrâ
    int x = (WINDOW_WIDTH - SQUARE_SIDE)/2;
    int y = (WINDOW_HEIGHT- SQUARE_SIDE)/2;
    graph_rect(x, y, SQUARE_SIDE, SQUARE_SIDE, c_green, true);

    // desenhar um círculo vermelho centrado de raio SQUARE_SIZE/4
    graph_circle(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, SQUARE_SIDE/4, c_red, true);
    graph_start();
    return 0;
}
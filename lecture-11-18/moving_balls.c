#include <pg/pglib.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define BALL_RADIUS 20
#define BALL_CLR c_orange
#define BALL_DX 5
#define TIMEBASE 20

typedef struct ball {
    int x, y;   // posição do centro
    RGB clr;    // cor
    int dx;     // deslocamento em x
    int radius; // raio
} ball_t;

// variáveis globais
ball_t ball;

ball_t ball_create(int x, int y, RGB clr, int radius) {
    ball_t ball = { .x = x, .y = y, .clr = clr, 
                    .radius = radius,
                    .dx = BALL_DX};
    return ball;
}

void ball_draw(ball_t b) {
    graph_circle(b.x, b.y, b.radius, b.clr, true);
}

ball_t ball_move(ball_t b) {
    b.x += b.dx;
    if (b.x + b.radius >= WINDOW_WIDTH) {
        b.dx = -b.dx;
    }
    else if(b.x - b.radius <= 0) {
        b.dx = -b.dx;
    }
    return b;
}

void timer_handler() {
    graph_rect(0,0, WINDOW_WIDTH, WINDOW_HEIGHT, c_white, true);
    ball = ball_move(ball);
    ball_draw(ball);
}

int main() {

    graph_init2("Moving Balls", WINDOW_WIDTH, WINDOW_HEIGHT);
     
    ball = ball_create(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, BALL_CLR, BALL_RADIUS);
    ball_draw(ball);
    graph_regist_timer_handler(timer_handler, TIMEBASE );
    graph_start();

   
    printf("end!");
    return 0;
}


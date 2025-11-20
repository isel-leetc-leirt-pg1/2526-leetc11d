#include <pg/pglib.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define BALL_RADIUS 20
#define BALL_CLR c_orange

#define BALL_DX 4
#define BALL_DY 4

#define BALL_INC_DX 2
#define BALL_MAX_DX 30

#define BALL_INC_DY 2
#define BALL_MAX_DY 20

 

#define TIMEBASE 20

typedef struct ball {
    int x, y;   // posição do centro
    RGB clr;    // cor
    int dx, dy;     // deslocamento em x e y
    int radius; // raio
} ball_t;

// variáveis globais
#define MAX_BALLS 30

ball_t balls[MAX_BALLS];

#define MAX_COLORS 4
RGB palete[MAX_COLORS];  

ball_t ball_create(int x, int y, RGB clr, int radius) {
    ball_t ball = { .x = x, .y = y, .clr = clr, 
                    .radius = radius,
                    .dx = BALL_DX, .dy = BALL_DY };
    return ball;
}

void ball_draw(ball_t b) {
    graph_circle(b.x, b.y, b.radius, b.clr, true);
}

void pallete_init() {
    palete[0] = c_red;
    palete[1] = c_orange;
    palete[2] = c_yellow;
    palete[3] = c_lightblue;
}

void ball_move(ball_t *b) {
    // ajustar x e dx
    b->x += b->dx;
    if (b->x + b->radius >= WINDOW_WIDTH) {
        b->dx = -b->dx;
    }
    else if(b->x - b->radius <= 0) {
        b->dx = -b->dx;
    }

    // ajustar y e dy
    b->y += b->dy;
    if (b->y + b->radius >= WINDOW_HEIGHT) {
        b->dy = -b->dy;
    }
    else if(b->y - b->radius <= 0) {
        b->dy = -b->dy;
    }
}

void ball_accelerate_x(ball_t *b) {
    if (b-> dx > 0) {
        if (b->dx < BALL_MAX_DX) {
                b->dx += BALL_INC_DX;
        }
    }
    else {
        if (b->dx > -BALL_MAX_DX) {
                b->dx -= BALL_INC_DX;
        }
    }
    

}


void ball_break_x(ball_t *b) {
    if (b->dx > 0) {
        b->dx -= BALL_INC_DX;
        if (b->dx < 0) {
            b->dx = 0;
        }
    }
    else {
        b->dx += BALL_INC_DX;
        if (b->dx > 0) {
            b->dx = 0;
        }

    }

}

void draw_background() {
  graph_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, c_green, true);
}

void balls_accelerate() {
     for(int i= 0; i < MAX_BALLS; ++i)  {
        ball_accelerate_x(&balls[i]);
     }
}

void balls_break() {
     for(int i= 0; i < MAX_BALLS; ++i)  {
        ball_break_x(&balls[i]);
     }
}

void balls_move() {
     for(int i= 0; i < MAX_BALLS; ++i)  {
        ball_move(&balls[i]);
     }
}


void  balls_draw() {
     for(int i= 0; i < MAX_BALLS; ++i)  {
        ball_draw(balls[i]);
     }
}




void timer_handler() {
    draw_background();
    balls_move();
    balls_draw();
}

void kbd_handler(KeyEvent ke) {
    if (ke.state == KEY_PRESSED) {
        switch(ke.keysym) {
            case SDLK_UP:
                balls_accelerate();
                break;
            case SDLK_DOWN:
                balls_break();
                break;
            default:
                break;
        }

    }

}



void create_balls() {
    for(int i= 0; i < MAX_BALLS; ++i) {
        balls[i] = ball_create(
            rand() % WINDOW_WIDTH, // x
            rand() % WINDOW_HEIGHT, // y
            palete[rand() % MAX_COLORS], // color
            10 + rand() % 20 // radius

        );
    }
}

int main() {

    graph_init2("Moving Balls", WINDOW_WIDTH, WINDOW_HEIGHT);
    draw_background();
    
    
    pallete_init();
    create_balls();

   
    graph_regist_timer_handler(timer_handler, TIMEBASE );

    graph_regist_key_handler(kbd_handler);
    graph_start();

   
    printf("end!");
    return 0;
}


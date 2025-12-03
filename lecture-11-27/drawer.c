#include <pg/pglib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 1000

int nevents=0;

int old_x=-1, old_y=-1;

void mouse_handler(MouseEvent me) {
    if (me.state == BUTTON_PRESSED) {
        if (me.button == BUTTON_LEFT) {
           graph_circle(me.x, me.y, 6, c_black, true);
            // if (old_x == -1) {
            //     old_x = me.x;
            //     old_y = me.y;
            // }
            // else {
            //     graph_line(old_x, old_y, me.x, me.y, c_black);
            //     old_x = me.x;
            //     old_y = me.y;
            // }
            
        }
    }
    else if (me.state == BUTTON_RELEASED) {
        old_x = -1;
        old_y = -1;
    }
    

    printf("mouse(%d)!\n", ++nevents);
}

int main() {
    graph_init2("Drawer", WINDOW_WIDTH, WINDOW_HEIGHT);

    graph_regist_mouse_handler(mouse_handler);

    graph_start();
    return 0;

}
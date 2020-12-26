#include <stdio.h>
#include "src/window.h"

void main() {
    Window w = create_window("Game Window", 600, 600);

    while(w.running) {
        // if(key_pressed("A"))
        //     printf("A was pressed!");

        update_window();
    }
}
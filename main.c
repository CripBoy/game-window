#include <stdio.h>
#include "core/window.h"

void main() {
    Window w = new_window("Game Window", 600, 300);

    while(w.running) {
        update_window(w);
    }
}
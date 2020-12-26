#include "./util.h"

void set_console_color(char * color) {
    printf(color);
}

void reset_console_color() {
    printf(ANSI_COLOR_RESET);
}

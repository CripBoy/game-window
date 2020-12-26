#ifndef WINDOW_H
#define WINDOW_H

#define WELCOME "Game Window"
#define VERSION "V1.0.0"

#include <windows.h>
#include "./util.h"

typedef struct {
    char * title;
    int width, height;
    int running;
    HWND ws_window;
    HDC ws_canvas;
} Window;

Window create_window(char * title, int width, int height);
void update_window();

#endif
#ifndef WINDOW_H
#define WINDOW_H
#include <windows.h>

typedef struct {
    char * title;
    int width, height;
    int running;
    HWND ws_window;
    HDC ws_canvas;
} Window;

Window new_window(char * title, int width, int height);
void update_window(Window wind);

#endif
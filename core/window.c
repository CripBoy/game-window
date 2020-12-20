#include <stdio.h>
#include <stdlib.h>
#include "./window.h"

LRESULT window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg) {
        case WM_DESTROY: {
            PostQuitMessage(0);
            exit(EXIT_SUCCESS);
        }

        return 0;
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void init_window(Window wind) {
    WNDCLASSA window_class = {0};

    window_class.style = CS_HREDRAW|CS_VREDRAW;
    window_class.lpfnWndProc = window_callback;
    window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class.lpszClassName = "GAME_WINDOW_CLASS";

    RegisterClassA(&window_class);

    wind.ws_window = CreateWindowEx(0,
        window_class.lpszClassName,
        wind.title,
        WS_VISIBLE|WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        wind.width, wind.height,
        NULL, NULL, NULL, NULL);
    wind.ws_canvas = GetDC(wind.ws_window);
}

void update_window(Window wind) {
    MSG message;

    while (GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}

Window new_window(char * title, int width, int height) {
    Window wind;

    wind.title = title;
    wind.width = width;
    wind.height = height;
    wind.running = 1;

    init_window(wind);

    return wind;
}
#include "./window.h"
#include "./util.h"

Window wind;

void startup_log() {
    set_console_color(ANSI_COLOR_CYAN);
    printf("%s %s\n", WELCOME, VERSION);
    reset_console_color();
}

LRESULT window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg) {
        case WM_DESTROY: {
            PostQuitMessage(false);
            exit(EXIT_SUCCESS);
        } break;

        case WM_KEYUP: {
            printf("cu rola buceta\n");
        } break;

        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void init_window() {
    WNDCLASSA window_class = {0};

    window_class.style = CS_HREDRAW|CS_VREDRAW;
    window_class.lpfnWndProc = window_callback;
    window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class.lpszClassName = "GAME_WINDOW_CLASS";

    RegisterClassA(&window_class);

    wind.ws_window = CreateWindowEx(0,
        window_class.lpszClassName,
        wind.title,
        WS_VISIBLE | WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        wind.width, wind.height,
        NULL, NULL, NULL, NULL);
    wind.ws_canvas = GetDC(wind.ws_window);

    startup_log();
}

void update_window() {
    MSG message;

    while (GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}

Window create_window(char * title, int width, int height) {
    wind.title = title;
    wind.width = width;
    wind.height = height;
    wind.running = true;

    init_window();

    return wind;
}
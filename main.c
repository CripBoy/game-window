#include <windows.h>

#define true 1
#define false 0
#define global_variable static
#define internal static

// state of the window for the main loop
static int running = true;

// message callback from window
LRESULT window_callback(
HWND window,
UINT message,
WPARAM w_param,
LPARAM l_param) {
    LRESULT result = false;

    switch(message) {
        // close or destroy the window
        case WM_CLOSE:
        case WM_DESTROY: {
            running = false;
        } break;
        default: {
            result = DefWindowProcA(window, message, w_param, l_param);
        }
    }

    return result;
};

// spawn window
int WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nShowCmd
){
    WNDCLASSA window_class = {0};
    window_class.style = CS_HREDRAW|CS_VREDRAW;
    window_class.lpfnWndProc = window_callback;
    window_class.lpszClassName = "GAME_WINDOW_CLASS";

    RegisterClassA(&window_class);

    HWND window = CreateWindowExA(
        0, // style
        window_class.lpszClassName, // class name
        "GAME WINDOW", // window name
        WS_VISIBLE|WS_OVERLAPPEDWINDOW, // display
        CW_USEDEFAULT, CW_USEDEFAULT, // position
        800, 640,  // size
        false, // Parent window    
        false, // Menu
        false, // Instance handle
        false // Additional application data
    );

    if(window == NULL)
        return false;

    while(running){
        // input
        MSG message;

        while(PeekMessageA(&message, window, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        // simulation

        // render
    }
};
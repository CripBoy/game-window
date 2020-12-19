#include <windows.h>
// #include <stdlib.h>
#include "util.c"
#include "render.c"

// screen buffer
Render_Buffer render_buffer;

// state of the window for the main loop
int running = true;

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
        case WM_SIZE: {
            // get width and height from the window
            RECT rect;
            GetWindowRect(window, &rect);
            render_buffer.width = rect.right - rect.left;
            render_buffer.height = rect.bottom - rect.top;

            // alocate to buffer
            if(render_buffer.pixels) {
                VirtualFree(render_buffer.pixels, 0, MEM_RELEASE);
            }

            render_buffer.pixels = VirtualAlloc(
                0,
                sizeof(u32) * render_buffer.width * sizeof(u32) * render_buffer.height,
                MEM_COMMIT|MEM_RESERVE,
                PAGE_READWRITE);

            // fill the bitmapinfo
            render_buffer.bitmap_info.bmiHeader.biSize = sizeof(render_buffer.bitmap_info.bmiHeader);
            render_buffer.bitmap_info.bmiHeader.biWidth = render_buffer.width;
            render_buffer.bitmap_info.bmiHeader.biHeight =- render_buffer.height;
            render_buffer.bitmap_info.bmiHeader.biPlanes = 1;
            render_buffer.bitmap_info.bmiHeader.biBitCount = 32;
            render_buffer.bitmap_info.bmiHeader.biCompression = BI_RGB;
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

    HDC hdc = GetDC(window);

    if(window == NULL)
        return false;

    while(running){
        // Input
        MSG message;

        while(PeekMessageA(&message, window, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        // Simulation
        clear_screen(0xffff00, render_buffer);

        // Render
        StretchDIBits(
            hdc, // canvas
            0, 0, // position
            render_buffer.width, render_buffer.height, // size position
            0, 0, // buffer position
            render_buffer.width, render_buffer.height, // buffer size
            render_buffer.pixels, // memory
            &render_buffer.bitmap_info, // image data
            DIB_RGB_COLORS,
            SRCCOPY
        );
    }
};
internal void clear_screen(u32 color, Render_Buffer render_buffer) {
    u32 * pixels = render_buffer.pixels;

    for(int y = 0; y < render_buffer.height; y++)
        for(int x = 0; x < render_buffer.width; x++) {
            *pixels++ = color;
        }
}
# Game Window Mannager
Helps you to create and mannage windows.h API windows in the most friendly way possible

**Usage**
```c
#include "core/window.h"

void main() {
    // create window - title; width; height
    Window w = new_window("Game Window", 600, 300);
  
    // update pool
    while(w.running) {
        update_window(w);
    }
}
```

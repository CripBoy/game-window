# game-window
Game window mannager for c

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

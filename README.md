# Game Window Mannager 🖥
Helps you to create and manage windows.h API in the most user-friendly way possible.<br/>
Perfect to indie game developers that want to abstract syntax for your games.

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

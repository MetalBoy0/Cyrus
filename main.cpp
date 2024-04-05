#define SDL_MAIN_HANDLED

#include "Render/renderer.h"

int main() {
    init(); 
    SDL_Window *window = createWindow("Software Renderer", 100, 100, 800, 600, 0);
    render(window);
    return 0;
     }
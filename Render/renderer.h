#ifndef RENDERER_H
#define RENDERER_H

#include "../SDL/SDL2/SDL.h"

void init();
void render(SDL_Window *window);
SDL_Window *createWindow(const char *title, int x, int y, int w, int h, Uint32 flags);



#endif
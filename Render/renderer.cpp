// Moved to SDL2 for now because setting up DirectX or openGL is a pain

#include "../Util/triangle.h"
#include "../Util/vector3.h"
#include "renderer.h"
#include "texture.h"

void init() { SDL_Init(SDL_INIT_VIDEO); }

SDL_Texture *red;

SDL_Window *createWindow(const char *title, int x, int y, int w, int h,
                         Uint32 flags) {
  return SDL_CreateWindow(title, x, y, w, h, flags);
}

void drawTriangle(SDL_Renderer *renderer, Triangle triangle) {
  SDL_Vertex points[3] = {{triangle.a.x, triangle.a.y},
                          {triangle.b.x, triangle.b.y},
                          {triangle.c.x, triangle.c.y}};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderGeometry(renderer, red, points, 3, 0, 0);
}

void render(SDL_Window *window) {
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  red = solidTexture(renderer, Vector3(255, 0, 0));

  Triangle triangle(Vector3(0, 0, 0), Vector3(100, 100, 0), Vector3(200, 0, 0));

  drawTriangle(renderer, triangle);

  SDL_RenderPresent(renderer);

  SDL_Event e;
  while (true) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_QUIT:
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
      }
    }
  }

  SDL_DestroyRenderer(renderer);
}
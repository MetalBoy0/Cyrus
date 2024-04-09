// Moved to SDL2 for now because setting up DirectX or openGL is a pain

#include "../Util/gameObject.h"
#include "../Util/vector3.h"
#include "renderer.h"
#include "texture.h"
#include <string>

Renderer::Renderer(const char *windowName, int w, int h, int x, int y, int fps) {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow(windowName, x, y, w, h, 0);

  numOfObjects = 0;

  renderer = SDL_CreateRenderer(window, -1, 0);
}

void Renderer::AddObject(GameObject *gameObject) {
  object[numOfObjects++] = gameObject;
}

// Renders all the game objects added to the renderer
// Returns true if the user exits the window
bool Renderer::render() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      return true;

    default:
      break;
    }
  }

  for (int i = 0; i < numOfObjects; i++) {
    GameObject *o = object[i];

    if (o->sprite->texture) {
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, o->sprite->texture, NULL, &o->sprite->rect);
      SDL_RenderPresent(renderer);
    }
  }
  
  


  return false;
}
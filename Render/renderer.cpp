// Moved to SDL2 for now because setting up DirectX or openGL is a pain

#include "../Util/gameObject.h"
#include "../Util/vector3.h"
#include "renderer.h"
#include "texture.h"
#include <chrono>
#include <iostream>
#include <string>


SDL_Texture *loadTexture(const char *path, SDL_Renderer *renderer) {
  SDL_Surface *surface = SDL_LoadBMP(path);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}

Renderer::Renderer(const char *windowName, int w, int h, int x, int y, int fps,
                   Vector3 backgroundColor) {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow(windowName, x, y, w, h, 0);

  numOfObjects = 0;

  renderer = SDL_CreateRenderer(window, -1, 0);

  this->backgroundColor = backgroundColor;

  lastFrameTime = 0;

  spf = 1000 / fps;
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

  SDL_SetRenderDrawColor(renderer, backgroundColor.x, backgroundColor.y,
                         backgroundColor.z, 255);
  SDL_RenderClear(renderer);

  for (int i = 0; i < numOfObjects; i++) {
    GameObject *o = object[i];

    if (o->sprite->texture) {
      SDL_RenderCopy(renderer, o->sprite->texture, NULL, &o->sprite->rect);
    }
  }

  SDL_RenderPresent(renderer);

  // Calculate deltaTime
  double deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::system_clock::now().time_since_epoch())
                         .count() -
                     lastFrameTime;

  // Wait until next frame time
  double remainingTime = spf - deltaTime;
  if (remainingTime > 0) {
    SDL_Delay(remainingTime);
  }

  double currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                           std::chrono::system_clock::now().time_since_epoch())
                           .count();

  std::cout << "FPS: " << 1000 / (currentTime - lastFrameTime) << std::endl;

  lastFrameTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                      std::chrono::system_clock::now().time_since_epoch())
                      .count();

  return false;
}
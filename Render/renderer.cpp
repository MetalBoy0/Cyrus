// Moved to SDL2 for now because setting up DirectX or openGL is a pain

#include "../Util/gameObject.h"
#include "../Util/vector3.h"
#include "renderer.h"
#include "sprite.h"
#include "texture.h"
#include <chrono>
#include <iostream>
#include <string>

void drawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY,
                int32_t radius) {
  const int32_t diameter = (radius * 2);

  int32_t x = (radius - 1);
  int32_t y = 0;
  int32_t tx = 1;
  int32_t ty = 1;
  int32_t error = (tx - diameter);

  while (x >= y) {
    //  Each of the following renders an octant of the circle
    SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
    SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
    SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
    SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
    SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
    SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
    SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
    SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

    if (error <= 0) {
      ++y;
      error += ty;
      ty += 2;
    }

    if (error > 0) {
      --x;
      tx += 2;
      error += (tx - diameter);
    }
  }
}

Renderer::Renderer(const char *windowName, int w, int h, int x, int y, int fps,
                   Vector3 backgroundColor) {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow(windowName, x, y, w, h, 0);

  numOfObjects = 0;

  renderer = SDL_CreateRenderer(window, -1, 0);

  this->backgroundColor = backgroundColor;

  lastFrameTime = 0;

  spf = 1000000 / fps;
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
      o->sprite->update();
      

      // Draw circle at position
      if (o->collider) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        // Draw hitbox
        for (int i = 0; i < o->collider->numPoints; i++) {
          drawCircle(renderer, o->collider->points[i].x + o->position.x,
                     o->collider->points[i].y + o->position.y, 2);
        }
      }
    }
  }

  SDL_RenderPresent(renderer);

  // Calculate deltaTime
  double deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(
                         std::chrono::system_clock::now().time_since_epoch())
                         .count() -
                     lastFrameTime;

  // Wait until next frame time
  double remainingTime = spf - deltaTime;
  if (remainingTime > 0) {
    SDL_Delay(remainingTime/1000);
  }

  double currentTime = std::chrono::duration_cast<std::chrono::microseconds>(
                           std::chrono::system_clock::now().time_since_epoch())
                           .count();

  std::cout << "FPS: " << 1000000 / (currentTime - lastFrameTime) << std::endl;

  lastFrameTime = std::chrono::duration_cast<std::chrono::microseconds>(
                      std::chrono::system_clock::now().time_since_epoch())
                      .count();

  return false;
}
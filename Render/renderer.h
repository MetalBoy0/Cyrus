#ifndef RENDERER_H
#define RENDERER_H

#include "../SDL/SDL2/SDL.h"
#include "../Util/gameObject.h"

SDL_Texture *loadTexture(const char *path, SDL_Renderer *renderer);

class Renderer {
public:
  Renderer(const char *windowName, int w, int h, int x = 0, int y = 0, int fps = 30, Vector3 backgroundColor = Vector3(0, 0, 0));

  void AddObject(GameObject *obj);
  bool render();
  SDL_Renderer *renderer;

private:
  Vector3 backgroundColor;
  SDL_Window *window;
  GameObject *object[256];
  int numOfObjects;
  double lastFrameTime;
  double spf; // milliseconds per frame 1000 / fps
};

#endif
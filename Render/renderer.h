#ifndef RENDERER_H
#define RENDERER_H

#include "../SDL/SDL2/SDL.h"
#include "../Util/gameObject.h"

class Renderer {
public:
  Renderer(const char *windowName, int w, int h, int x = 0, int y = 0, int fps = 30);

  void AddObject(GameObject *obj);
  bool render();
  SDL_Renderer *renderer;

private:
  SDL_Window *window;
  GameObject *object[256];
  int numOfObjects;
};

#endif
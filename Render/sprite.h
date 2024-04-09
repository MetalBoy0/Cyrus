#ifndef SPRITE_H
#define SPRITE_H
#include "../SDL/SDL2/SDL.h"

class Sprite {
public:
  Sprite() { width = height = 0; }
  Sprite(int width, int height) {
    this->width = width;
    this->height = height;
  }
  Sprite(const Sprite *s) {
    this->height = s->height;
    this->width = s->width;
    this->texture = s->texture;
  }

  void assignTexture(SDL_Texture *texture, int x, int y) {
    this->texture = texture;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
  }

  int width, height;
  SDL_Texture *texture;
  SDL_Rect rect;
};

#endif
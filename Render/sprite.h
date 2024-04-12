#ifndef SPRITE_H
#define SPRITE_H

#include "../SDL/SDL2/SDL.h"
#include "../Util/gameObject.h"

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
    if (gameObject) {
      rect.x = gameObject->position.x;
      rect.y = gameObject->position.y;
    }
    rect.w = width;
    rect.h = height;
  }

  // Updates the texture based off of the GameObject
  void update();

  int width, height;
  SDL_Texture *texture;
  SDL_Rect rect;
  GameObject *gameObject = nullptr;
};

#endif
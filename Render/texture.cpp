#include "texture.h"

// Create a 1x1 texture with the specified color
SDL_Texture *solidTexture(SDL_Renderer *renderer, Vector3 color, int w, int h) {

  SDL_Surface *surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL,
               SDL_MapRGB(surface->format, color.x, color.y, color.z));
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}

// Load a texture from file
SDL_Texture *loadTexture(const char *path, SDL_Renderer *renderer) {
  SDL_Surface *surface = SDL_LoadBMP(path);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}
#ifndef TEXTURE_H
#define TEXTURE_H

#include "../SDL/SDL2/SDL.h"
#include "../Util/vector3.h"

SDL_Texture *solidTexture(SDL_Renderer *renderer, Vector3 color, int w, int h);
SDL_Texture *loadTexture(const char *path, SDL_Renderer *renderer);
SDL_Texture *surfaceToTexture(SDL_Surface *surface, SDL_Renderer *renderer);
SDL_Surface *loadSurface(const char *path);
SDL_Surface *solidSurface(Vector3 color, int w, int h);

#endif
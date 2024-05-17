#include "../Render/texture.h"
#include "collisions.h"

int getR(Uint32 pixel) { return (pixel & 0x00FF0000) >> 16; }
int getG(Uint32 pixel) { return (pixel & 0x0000FF00) >> 8; }
int getB(Uint32 pixel) { return (pixel & 0x000000FF); }
int getA(Uint32 pixel) { return (pixel & 0xFF000000) >> 24; }

bool Collider::check_collision(Collider *GameObject, float coord[2]) {}

// Load the points from a texture into the points array
void Collider::loadPoints(SDL_Surface *surface) {
  // Load the pixels of the texture into an array
  int w, h;

  w = surface->w;
  h = surface->h;

  Uint32 *pixels = (Uint32 *)surface->pixels;
  Vector3 edgePoints[w * h];
  int numEdge = 0;
  // Simple edge detection by checking if the pixel is next to a transparent
  // pixel
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      int index = i + j * w;
      int r = getR(pixels[index]);
      int g = getG(pixels[index]);
      int b = getB(pixels[index]);
      int a = getA(pixels[index]);

      if (a == 255) {
        continue;
      }

      // Check if the pixel is next to a transparent pixel
      if (i > 0 && getA(pixels[index - 1]) == 255) {
        edgePoints[numEdge++] = Vector3(i, j, 0);
      } else if (i < w - 1 && getA(pixels[index + 1]) == 255) {
        edgePoints[numEdge++] = Vector3(i, j, 0);
      } else if (j > 0 && getA(pixels[index - w]) == 255) {
        edgePoints[numEdge++] = Vector3(i, j, 0);
      } else if (j < h - 1 && getA(pixels[index + w]) == 255) {
        edgePoints[numEdge++] = Vector3(i, j, 0);
      }
    }
  }
  // order them by distance to each other
  for (int i = 0; i < numEdge; i++) {
    Vector3 point = edgePoints[i];
    for (int j = i + 1; j < numEdge; j++) {
      if ((point - edgePoints[j]).magnitude() < 2) {
        Vector3 temp = edgePoints[i + 1];
        edgePoints[i + 1] = edgePoints[j];
        edgePoints[j] = temp;
        break;
      }
    }
  }

  // This spot decides where to put the points along the edge
  // This will detect when the edge changes by detecting when a point deviates
  // from it
  float averageEdge = 0;
  float maxDeviation = 2;
  int roundCounter = 0;
  int edgeCounter = 0;
  int numPoints = 0;

  for (int i = 0; i < numEdge; i++) {
    Vector3 point = edgePoints[i];
    Vector3 nextPoint = edgePoints[(i + 1) % numEdge];
    float dir = (nextPoint - point).angle();
    if (abs(dir - averageEdge) > maxDeviation) {
      // TODO: do a further back search to check if the point is a corner or
      // Corner or round edge detected
      points[numPoints++] = point;
      roundCounter++;
      edgeCounter = 0;
    } else {
      edgeCounter++;
      roundCounter = 0;
    }
    averageEdge += dir / roundCounter;
  }
}
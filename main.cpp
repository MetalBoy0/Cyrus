#define SDL_MAIN_HANDLED

#include "Render/renderer.h"
#include "Render/texture.h"

int main() {

  Renderer renderer("Window", 800, 600, SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED);

  GameObject redSquare(Vector3(50, 50, 0), Vector3(0, 0, 0));
  SDL_Texture *red =
      solidTexture(renderer.renderer, Vector3(255, 0, 0), 50, 50);
  Sprite redSprite(50, 50);
  redSprite.assignTexture(red, redSquare.position.x, redSquare.position.y);
  redSquare.sprite = &redSprite;
  renderer.AddObject(&redSquare);

  float gravitySpeed = 0;

  while (true) {
    gravitySpeed += 0.001;
    // renderer.render() returns true when the user quits the window
    if (renderer.render())
      break;
    redSquare.updatePos(redSquare.position + Vector3(0, gravitySpeed, 0));
  }

  // Destroys all windows and cleans up GameObject textures
  // renderer.cleanUp();

  return 0;
}
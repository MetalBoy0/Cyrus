#define SDL_MAIN_HANDLED

#include "Render/renderer.h"
#include "Render/sprite.h"
#include "Render/texture.h"

int main() {

  // Initialize Renderer
  Renderer renderer("Window", 800, 600, SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED, 60, Vector3(255, 255, 255));

  // Create stickman gameObject
  GameObject stickMan(Vector3(50, 50, 0), Vector3(0, 0, 0));

  // Create a stickman sprite with the dimensons 38, 91
  Sprite stickManSprite(45, 100);
  SDL_Surface *stickManSurface = loadSurface("stickman.bmp");
  SDL_Texture *stickManTexture = surfaceToTexture(stickManSurface, renderer.renderer);
  stickManSprite.assignTexture(stickManTexture, stickMan.position.x,
                               stickMan.position.y);
  stickManSprite.rotation = 0;

  // Assign the sprite to the gameObject for rendering
  stickMan.assignSprite(&stickManSprite);

  // colliders
  Collider stickManCollider;

  stickManCollider.loadPoints(stickManSurface, renderer.renderer);
  stickMan.collider = &stickManCollider;

  // Adds the renderer's gameObject array
  renderer.AddObject(&stickMan);

  int ySpeed = 3;
  int xSpeed = 5;
  while (true) {
    // renderer.render() returns true when the user quits the window
    if (renderer.render())
      break;
    if (stickMan.position.y > 600 - 100 ||
        stickMan.position.y < 0) // If it goes off screen
      ySpeed = -ySpeed;          // Reverse speed
    if (stickMan.position.x > 800 - 45 || stickMan.position.x < 0)
      xSpeed = -xSpeed;
    stickManSprite.rotation += 0;

    stickMan.position = stickMan.position + Vector3(xSpeed, ySpeed, 0);
  }

  // Destroys all windows and cleans up GameObject textures
  // renderer.cleanUp();

  return 0;
}
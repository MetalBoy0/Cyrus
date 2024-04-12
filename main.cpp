#define SDL_MAIN_HANDLED

#include "Render/renderer.h"
#include "Render/texture.h"
#include "Render/sprite.h"

int main() {

  // Initialize Renderer
  Renderer renderer("Window", 800, 600, SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED, 60, Vector3(255, 255, 255));

  // Create stickman gameObject
  GameObject stickMan(Vector3(50, 50, 0), Vector3(0, 0, 0));

  // Assign stickman texture to gameObject
  SDL_Texture *stickManTexture = loadTexture("stickman.bmp", renderer.renderer);

  // Create a stickman sprite with the dimensons 38, 91
  Sprite stickManSprite(38, 91);

  // Assign the previously loaded stickman texture
  stickManSprite.assignTexture(stickManTexture, stickMan.position.x,
                               stickMan.position.y);

  // Assign the sprite to the gameObject for rendering
  stickMan.assignSprite(&stickManSprite);

  // Adds the renderer's gameObject array
  renderer.AddObject(&stickMan);

  float gravitySpeed = 0;

  while (true) {
    gravitySpeed += 0.5;
    // renderer.render() returns true when the user quits the window
    if (renderer.render())
      break;
    stickMan.position = stickMan.position + Vector3(0, gravitySpeed, 0); // Apply gravity
    if (stickMan.position.y > 600) // If it goes off screen
      gravitySpeed = -gravitySpeed - 0.5; // Reverse speed
  }

  // Destroys all windows and cleans up GameObject textures
  // renderer.cleanUp();

  return 0;
}
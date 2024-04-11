#define SDL_MAIN_HANDLED

#include "Render/renderer.h"
#include "Render/texture.h"

int main() {

  // Initialize Renderer
  Renderer renderer("Window", 800, 600, SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED, 60, Vector3(255, 255, 255));

  // Create stickman gameObject
  GameObject stickMan(Vector3(50, 50, 0), Vector3(0, 0, 0));

  // Assign stickman texture to gameObject
  SDL_Texture *stickManTexture = loadTexture("stickman.bmp", renderer.renderer);

  Sprite stickManSprite(38, 91);
  stickManSprite.assignTexture(stickManTexture, stickMan.position.x,
                               stickMan.position.y);
  stickMan.sprite = &stickManSprite;

  renderer.AddObject(&stickMan);

  float gravitySpeed = 0;

  while (true) {
    gravitySpeed += 0.5;
    // renderer.render() returns true when the user quits the window
    if (renderer.render())
      break;
    stickMan.updatePos(stickMan.position + Vector3(0, gravitySpeed, 0));
    if (stickMan.position.y > 600)
      gravitySpeed = -gravitySpeed - 0.5;
  }

  // Destroys all windows and cleans up GameObject textures
  // renderer.cleanUp();

  return 0;
}
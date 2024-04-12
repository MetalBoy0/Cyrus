#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vector3.h"
#include "../Physics/collisions.h"

class Sprite;

// Initialize with position and rotation vector
class GameObject {
public:
  GameObject() : position(Vector3()), rotation(Vector3()){};
  GameObject(Vector3 position, Vector3 rotation)
      : position(position), rotation(rotation){};
  GameObject(const GameObject &g)
      : position(g.position), rotation(g.rotation){};

  void assignSprite(Sprite *sprite);
  Vector3 position;
  Vector3 rotation;

  Sprite *sprite = nullptr;
  Collider *collider = nullptr;
};

#endif
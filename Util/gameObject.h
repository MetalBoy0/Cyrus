#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Physics/collisions.h"
#include "../Render/sprite.h"
#include "../Util/vector3.h"

// Initialize with position and rotation vector
class GameObject {
public:
  GameObject() : position(Vector3()), rotation(Vector3()){};
  GameObject(Vector3 position, Vector3 rotation)
      : position(position), rotation(rotation){};
  GameObject(const GameObject &g)
      : position(g.position), rotation(g.rotation){};

  /* Updates the position vector to the new vector and automatically adjusts the  
  sprite and collider with it
  */
  void updatePos(Vector3 newPos);

  Vector3 position;
  Vector3 rotation;

  Sprite *sprite = nullptr;
  Collider *collider = nullptr;
};

#endif
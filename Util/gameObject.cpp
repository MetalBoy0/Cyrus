#include "gameObject.h"

void GameObject::updatePos(Vector3 newPos) {
    position = newPos;
    if (sprite) {
        sprite->rect.x = newPos.x;
        sprite->rect.y = newPos.y;
    }
}
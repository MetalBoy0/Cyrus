#include "sprite.h"


void Sprite::update() {
    rect.x = gameObject->position.x;
    rect.y = gameObject->position.y;
}
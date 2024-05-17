#include "gameObject.h"
#include "../Render/sprite.h"


void GameObject::assignSprite(Sprite *sprite) {
    this->sprite = sprite;
    this->sprite->gameObject = this;
}

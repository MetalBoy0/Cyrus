#include "sprite.h"
#include <cmath>

void Sprite::update() {
    rect.x = gameObject->position.x;
    rect.y = gameObject->position.y;

    // Update the bounding box according to rotation

    // Get the center of the sprite
    int x = rect.x + rect.w / 2;
    int y = rect.y + rect.h / 2;

    // Get the corners of the sprite
    Vector3 corners[4] = {
        Vector3(rect.x, rect.y, 0),
        Vector3(rect.x + rect.w, rect.y, 0),
        Vector3(rect.x, rect.y + rect.h, 0),
        Vector3(rect.x + rect.w, rect.y + rect.h, 0)};

    // Rotate the corners
    for (int i = 0; i < 4; i++) {
        corners[i] = corners[i].rotateAround(Vector3(x, y,0), rotation);
    }

    // Get the min and max values
    int minX = corners[0].x;
    int minY = corners[0].y;
    int maxX = corners[0].x;
    int maxY = corners[0].y;

    for (int i = 1; i < 4; i++) {
        if (corners[i].x < minX) {
            minX = corners[i].x;
        }
        if (corners[i].y < minY) {
            minY = corners[i].y;
        }
        if (corners[i].x > maxX) {
            maxX = corners[i].x;
        }
        if (corners[i].y > maxY) {
            maxY = corners[i].y;
        }
    }

    boundingBox.x = minX;
    boundingBox.y = minY;
    boundingBox.w = maxX - minX;
    boundingBox.h = maxY - minY;
}
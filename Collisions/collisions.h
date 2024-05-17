#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "../Util/vector3.h"
#include "../SDL/SDL2/SDL.h"

// Some sort of collider class to include in a GameObject
class Collider {
    public:
 
    bool check_collision(Collider * GameOjbect, float coord[2]);

    void loadPoints(SDL_Surface *surface);


    Vector3 points[256];
    int numPoints = 0;

};

#endif
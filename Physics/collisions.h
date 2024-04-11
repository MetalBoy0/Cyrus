#ifndef COLLISIONS_H
#define COLLISIONS_H

// Some sort of collider class to include in a GameObject
class Collider {
    public:

    Collider(float x, float y) {
        //learning how to use classes because i'm dumb
    }
    void update();
    bool check_collision(Collider * GameOjbect, float coord[2]);

};

#endif 
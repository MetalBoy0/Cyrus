#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector3.h"

class Triangle {
public:
  Vector3 a, b, c;

  Triangle() : a(Vector3()), b(Vector3()), c(Vector3()){};
  Triangle(Vector3 a, Vector3 b, Vector3 c) : a(a), b(b), c(c){};
  Triangle(const Triangle &t) : a(t.a), b(t.b), c(t.c){};
};

#endif
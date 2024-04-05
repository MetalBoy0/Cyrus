// This file defines the Vector3 class
// The Vector3 class allows you to store useful things such as coordinates or
// color

// I know that we are using 2D graphics, so just use the x and y values for
// coordinates The z value can be used for depth

// Example:
// Vector3 v(1, 2, 3);
// Vector3 v2(4, 5, 6);
// Vector3 v3 = v + v2;
// Vector 3 is (5, 7, 9)

#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

class Vector3 {
public:
  float x, y, z;

  Vector3() : x(0), y(0), z(0){};
  Vector3(float x, float y, float z) : x(x), y(y), z(z){};
  Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z){};

  Vector3 operator+(const Vector3 &v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
  };
  Vector3 operator-(const Vector3 &v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
  };
  Vector3 operator*(float f) const { return Vector3(x * f, y * f, z * f); };
  Vector3 operator/(float f) const { return Vector3(x / f, y / f, z / f); };

  Vector3 &operator+=(const Vector3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  };
  Vector3 &operator-=(const Vector3 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  };
  Vector3 &operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
  };
  Vector3 &operator/=(float f) {
    x /= f;
    y /= f;
    z /= f;
    return *this;
  };

  bool operator==(const Vector3 &v) const {
    return x == v.x && y == v.y && z == v.z;
  };
  bool operator!=(const Vector3 &v) const {
    return x != v.x || y != v.y || z != v.z;
  };

  float dot(const Vector3 &v) const { return x * v.x + y * v.y + z * v.z; };
  Vector3 cross(const Vector3 &v) const {
    return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
  };
  float magnitude() const { return sqrt(x * x + y * y + z * z); };
  Vector3 normalize() const { return *this / magnitude(); };
};

#endif
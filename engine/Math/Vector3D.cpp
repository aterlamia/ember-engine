//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Vector3D.h"

Vector3D::Vector3D() {
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
}

Vector3D::Vector3D(
    const float &x,
    const float &y,
    const float &z

) : x(x)
    , y(y)
    , z(z) {}

Vector3D &Vector3D::divide(const Vector3D &vector) {
  x /= vector.x;
  y /= vector.y;
  z /= vector.z;
  return *this;
}

Vector3D &Vector3D::add(const Vector3D &vector) {
  x += vector.x;
  y += vector.y;
  z += vector.z;
  return *this;
}

Vector3D &Vector3D::substract(const Vector3D &vector) {
  x -= vector.x;
  y -= vector.y;
  z -= vector.z;
  return *this;
}

Vector3D &Vector3D::multiply(const Vector3D &vector) {
  x *= vector.x;
  y *= vector.y;
  z *= vector.z;
  return *this;
}

std::ostream &operator<<(
    std::ostream &out,
    const Vector3D &vector
) {
  out << "vector(" << vector.x << "," << vector.y << "," << vector.z << ")";
  return out;
}

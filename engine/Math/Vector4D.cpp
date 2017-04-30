//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Vector4D.h"

Vector4D::Vector4D() {
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
  w = 0.0f;
}

Vector4D::Vector4D(
    const float &x,
    const float &y,
    const float &z,
    const float &w
) : x(x)
    , y(y)
    , z(z)
    , w(w) {}

Vector4D &Vector4D::divide(const Vector4D &vector) {
  x /= vector.x;
  y /= vector.y;
  z /= vector.z;
  w /= vector.w;
  return *this;
}

Vector4D &Vector4D::add(const Vector4D &vector) {
  x += vector.x;
  y += vector.y;
  z += vector.z;
  w += vector.w;
  return *this;
}

Vector4D &Vector4D::substract(const Vector4D &vector) {
  x -= vector.x;
  y -= vector.y;
  z -= vector.z;
  w -= vector.w;
  return *this;
}

Vector4D &Vector4D::multiply(const Vector4D &vector) {
  x *= vector.x;
  y *= vector.y;
  z *= vector.z;
  w *= vector.w;
  return *this;
}

std::ostream &operator<<(
    std::ostream &out,
    const Vector4D &vector
) {
  out << "vector4d(" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << ")\n";
  return out;
}

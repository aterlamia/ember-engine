//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Vector2D.h"

Vector2D::Vector2D() {
  x = 0.0f;
  y = 0.0f;
}

Vector2D::Vector2D(
    const float &x,
    const float &y
) : x(x)
    , y(y) {}

Vector2D &Vector2D::divide(const Vector2D &vector) {
  x /= vector.x;
  y /= vector.y;
  return *this;
}

Vector2D &Vector2D::add(const Vector2D &vector) {
  x += vector.x;
  y += vector.y;
  return *this;
}

Vector2D &Vector2D::substract(const Vector2D &vector) {
  x -= vector.x;
  y -= vector.y;
  return *this;
}

Vector2D &Vector2D::multiply(const Vector2D &vector) {
  x *= vector.x;
  y *= vector.y;
  return *this;
}

std::ostream &operator<<(
    std::ostream &out,
    const Vector2D &vector
) {
  out << "vector(" << vector.x << "," << vector.y << ")";
  return out;
}
//
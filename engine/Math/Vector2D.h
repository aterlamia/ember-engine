//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_VECTOR2D_H
#define EMBER_CORE_VECTOR2D_H

#include <ostream>

class Vector2D {
  public:
    float x;
    float y;

    Vector2D();
    Vector2D(
        const float &x,
        const float &y
    );

    Vector2D &add(const Vector2D &vector);
    Vector2D &substract(const Vector2D &vector);
    Vector2D &multiply(const Vector2D &vector);
    Vector2D &divide(const Vector2D &vector);

    friend std::ostream &operator<<(std::ostream &out, const Vector2D &vector);
};


#endif //EMBER_CORE_VECTOR2D_H

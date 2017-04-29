//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_VECTOR4D_H
#define EMBER_CORE_VECTOR4D_H


#include <ostream>

class Vector4D {
  public:
    float x;
    float y;
    float z;
    float w;

    Vector4D();

    Vector4D(
        const float &x,
        const float &y,
        const float &z,
        const float &w
    );

    Vector4D &add(const Vector4D &vector);
    Vector4D &substract(const Vector4D &vector);
    Vector4D &multiply(const Vector4D &vector);
    Vector4D &divide(const Vector4D &vector);

    friend std::ostream &operator<<(std::ostream &out, const Vector4D &vector);
};


#endif //EMBER_CORE_VECTOR4D_H

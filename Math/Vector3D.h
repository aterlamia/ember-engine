//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_VECTOR3D_H
#define EMBER_CORE_VECTOR3D_H

#include <ostream>

class Vector3D {
  public:
    float x;
    float y;
    float z;

    Vector3D();

    Vector3D(
        const float &x,
        const float &y,
        const float &z
    );

    Vector3D &add(const Vector3D &vector);
    Vector3D &substract(const Vector3D &vector);
    Vector3D &multiply(const Vector3D &vector);
    Vector3D &divide(const Vector3D &vector);

    friend std::ostream &operator<<(std::ostream &out, const Vector3D &vector);
};


#endif //EMBER_CORE_VECTOR3D_H

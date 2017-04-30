//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_MATRIX_H
#define EMBER_CORE_MATRIX_H


#include "Vector3D.h"

class Matrix {
  public:
    float elements[16];
    Matrix();
    Matrix(float diagonal);

    Matrix &multiply(const Matrix matrix);
    static Matrix identity();
    static Matrix orthograpic(
        float left,
        float right,
        float bottom,
        float top,
        float near,
        float far
    );

    static Matrix perspective(
        float fov,
        float ratio,
        float near,
        float far
    );

    static Matrix translation(const Vector3D &translation);
    static Matrix rotation(
        float angle,
        const Vector3D &axis
    );
    static Matrix scale(const Vector3D &scale);

    friend Matrix operator*(
        Matrix matrix1,
        const Matrix matrix2
    );
    friend Matrix operator*=(
        Matrix matrix1,
        const Matrix &matrix2
    );

    friend std::ostream &operator<<(
        std::ostream &out,
        const Matrix &matrix
    );
};

#endif //EMBER_CORE_MATRIX_H

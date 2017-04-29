//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <cmath>
#include "Matrix.h"
#include "Math.h"

Matrix::Matrix() {
  for (int i = 0; i < 16; i++) {
    elements[i] = 0.0f;
  }

}

Matrix::Matrix(float diagonal) {
  Matrix();
  elements[0] = diagonal;
  elements[5] = diagonal;
  elements[10] = diagonal;
  elements[15] = diagonal;
}

Matrix &Matrix::multiply(const Matrix matrix) {
  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      float total = 0.0f;
      for (int z = 0; z < 4; z++) {
        total += elements[y + z * 4] * matrix.elements[z + x * 4];
      }
      elements[y + y * 4] = total;
    }
  }
  return *this;
}

Matrix Matrix::identity() {
  return Matrix(1.0f);
}

Matrix Matrix::orthograpic(
    float left,
    float right,
    float top,
    float bottom,
    float near,
    float far
) {
  Matrix result(1.0f);

  result.elements[0] = 2.0f / (right - left);
  result.elements[5] = 2.0f / (top - bottom);
  result.elements[10] = 2.0f / (near - far);

  result.elements[12] = (left + right) / (left - right);
  result.elements[13] = (bottom + top) / (bottom - top);
  result.elements[14] = (far + near) / (far - near);

  return result;
}

Matrix Matrix::perspective(
    float fov,
    float ratio,
    float near,
    float far
) {
  Matrix result(1.0f);

  result.elements[0] = 1.0f / tan(Math::toRadians(0.5f * fov));;
  result.elements[5] = result.elements[0] / ratio;
  result.elements[10] = (near + far) / (near - far);
  result.elements[11] = -1.0f;
  result.elements[14] = (2.0f * near + far) / (near - far);;
  return result;
}

Matrix Matrix::translation(const Vector3D &translation) {
  Matrix result(1.0f);

  result.elements[12] = translation.x;
  result.elements[13] = translation.y;
  result.elements[14] = translation.z;

  return result;
}

Matrix Matrix::rotation(
    float angle,
    const Vector3D &axis
) {
  Matrix result(1.0f);

  float radians = Math::toRadians(angle);
  float co = cos(radians);
  float si = sin(radians);

  //row 1
  result.elements[0] = axis.x * (1.0f - co) + co;
  result.elements[1] = axis.x * axis.y * (1.0f - co) + axis.z * si;
  result.elements[2] = axis.x * axis.z * (1.0f - co) - axis.y * si;

  //row 2
  result.elements[4] = axis.x * axis.y * (1.0f - co) - axis.z * si;
  result.elements[5] = axis.y * (1.0f - co) + co;
  result.elements[6] = axis.y * axis.z * (1.0f - co) + axis.x * si;

  //row 3
  result.elements[8] = axis.x * axis.z * (1.0f - co) + axis.y * si;
  result.elements[9] = axis.y * axis.z * (1.0f - co) - axis.x * si;
  result.elements[10] = axis.z * (1.0f - co) + co;

  return result;
}

Matrix Matrix::scale(const Vector3D &scale) {
  Matrix result(1.0f);

  result.elements[0] = scale.x;
  result.elements[5] = scale.y;
  result.elements[10] = scale.z;

  return result;
}

Matrix operator*(
    Matrix matrix1,
    const Matrix matrix2
) {
  return matrix1.multiply(matrix2);
}

Matrix operator*=(
    Matrix matrix1,
    const Matrix &matrix2
) {
  return
      matrix1.multiply(matrix2);
}

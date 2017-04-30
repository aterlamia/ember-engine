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
  for (int i = 0; i < 16; i++) {
    elements[i] = 0.0f;
  }
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
    float left, float right, float bottom, float top, float near, float far
) {
  Matrix result(1.0f);

  result.elements[0] = 2.0f / (right - left);
  result.elements[5] = 2.0f / (top - bottom);
  result.elements[10] = 2.0f / (near - far);

  result.elements[3] = (left + right) / (left - right);
  result.elements[7] = (bottom + top) / (bottom - top);
  result.elements[11] = (far + near) / (far - near);

  return result;
}

Matrix Matrix::perspective(
    float fov,
    float ratio,
    float near,
    float far
) {
  Matrix result(1.0f);
  result.elements[5] = 1.0f / tan(Math::toRadians(0.5f * fov));
  result.elements[0] = result.elements[5] / ratio;
  result.elements[10] = (near + far) / (near - far);
  result.elements[11] = (2.0f * near + far) / (near - far);
  result.elements[14] = -1.0f;
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

std::ostream &operator<<(
    std::ostream &out,
    const Matrix &matrix
) {
  out << "=================MAtRIX 4x4==================\n";
  out << "[" << matrix.elements[0] << "," << matrix.elements[1] << "," << matrix.elements[2] << ","
      << matrix.elements[3] << "]\n";
  out << "[" << matrix.elements[4] << "," << matrix.elements[5] << "," << matrix.elements[6] << ","
      << matrix.elements[7] << "]\n";
  out << "[" << matrix.elements[8] << "," << matrix.elements[9] << "," << matrix.elements[10] << ","
      << matrix.elements[11] << "]\n";
  out << "[" << matrix.elements[12] << "," << matrix.elements[13] << "," << matrix.elements[14] << ","
      << matrix.elements[15] << "]\n";
  return out;
}

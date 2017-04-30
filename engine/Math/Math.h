//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_MATH_H
#define EMBER_CORE_MATH_H


#include <math.h>

struct Math {

  static float toRadians(float angle) {
    return angle * (M_PI / 180);

  } 

  static float toDegrees(float radians) {
    return (radians * 180) / M_PI;
  }
};


#endif //EMBER_CORE_MATH_H

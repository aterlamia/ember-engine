//
// Created by melvin on 28-5-17.
//

#include <glm/detail/type_mat.hpp>
#include <sstream>
#include <iomanip>
#include "string"
#ifndef EMBER_CORE_TOSTRING_H
#define EMBER_CORE_TOSTRING_H
namespace Ember {
  std::string toString(glm::mat4 const & matrix) {
    std::ostringstream os;
    for (int i = 0; i <= 3; i++) {
      os << "[ ";
      for (int j = 0; j <= 3; j++) {
        os << std::setw(10) << matrix[i][j];
        if (j < 3) {
          os << ", ";
        }
      }
      os << " ]" << std::endl;
    }
    return os.str();
  }
}
#endif //EMBER_CORE_TOSTRING_H

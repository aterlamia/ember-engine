//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_RENDERABLE_H
#define EMBER_CORE_RENDERABLE_H

#include <glm/glm.hpp>

struct VertexData {
  glm::vec3 vertex;
  glm::vec4 color;
};

class Renderable {
  private:
    glm::vec3 position;
    glm::vec4 color;
    glm::vec2 size;
  public:
    Renderable();
    Renderable(
        const glm::vec3 &position,
        const glm::vec4 &color,
        const glm::vec2 &size
    );
    const glm::vec3 &getPosition() const;
    const glm::vec4 &getColor() const;
    const glm::vec2 &getSize() const;
};
#endif //EMBER_CORE_RENDERABLE_H

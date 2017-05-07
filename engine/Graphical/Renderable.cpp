//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Renderable.h"

Renderable::Renderable() {
  position = glm::vec3(0.0f);
  color    = glm::vec4(1.0f);
  size     = glm::vec2(0.0f);
}

Renderable::Renderable(
    const glm::vec3 &position,
    const glm::vec4 &color,
    const glm::vec2 &size
) : position(position)
    , color(color)
    , size(size) {}

const glm::vec3 &Renderable::getPosition() const {
  return position;
}

const glm::vec4 &Renderable::getColor() const {
  return color;
}

const glm::vec2 &Renderable::getSize() const {
  return size;
}

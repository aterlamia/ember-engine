//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Renderable.h"

Renderable::Renderable() {
  position = glm::vec3(0.0f);
  color    = glm::vec4(1.0f);
  size     = glm::vec2(0.0f);
  texture.push_back(glm::vec2(0.0f, 0.0f));
  texture.push_back(glm::vec2(0.0f, 1.0f));
  texture.push_back(glm::vec2(1.0f, 1.0f));
  texture.push_back(glm::vec2(1.0f, 0.0f));
}

Renderable::Renderable(
    const glm::vec3 &position,
    const glm::vec4 &color,
    const glm::vec2 &size
) : position(position)
    , color(color)
    , size(size) {
  setDefaultUV();
}

void Renderable::setDefaultUV() {
  texture.push_back(glm::vec2(0.25f, 0.25f));
  texture.push_back(glm::vec2(0.25f, 0.50f));
  texture.push_back(glm::vec2(0.50f, 0.50f));
  texture.push_back(glm::vec2(0.50f, 0.25f));
}

const glm::vec3 &Renderable::getPosition() const {
  return position;
}

const glm::vec4 &Renderable::getColor() const {
  return color;
}

const glm::vec2 &Renderable::getSize() const {
  return size;
}

const std::vector<glm::vec2> &Renderable::getTexture() const {
    return texture;
}

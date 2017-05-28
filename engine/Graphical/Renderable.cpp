//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Renderable.h"
#include "Texture.h"

Renderable::Renderable() {
  position = glm::vec3(0.0f);
  color = glm::vec4(1.0f);
  size = glm::vec2(0.0f);
  setDefaultUV();
}

Renderable::Renderable(
    const glm::vec3 &position,
    const glm::vec4 &color,
    const glm::vec2 &size
) : position(position), color(color), size(size) {
  setDefaultUV();
}

Renderable::Renderable(
    const glm::vec3 &position,
    const glm::vec2 &size,
    Ember::Texture *texture) : position(position), color(color), size(size), texture(texture) {
  setDefaultUV();
}

void Renderable::setDefaultUV() {
  uv.push_back(glm::vec2(0.0f, 0.0f));
  uv.push_back(glm::vec2(0.0f, 1.0f));
  uv.push_back(glm::vec2(1.0f, 1.0f));
  uv.push_back(glm::vec2(1.0f, 0.0f));
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

const std::vector<glm::vec2> &Renderable::getUV() const {
  return uv;
}
void Renderable::setFrame(const glm::vec2 &position, const glm::vec2 &size) {

  if (texture == nullptr) {
    return;
  }
  float left = position.x / texture->getWidth();
  float right = (position.x + size.x) / texture->getWidth();
  float bottom = position.y / texture->getHeight();
  float top = (position.y + size.y) / texture->getHeight();

  uv[0] = glm::vec2(left, bottom);
  uv[1] = glm::vec2(left, top);
  uv[2] = glm::vec2(right, top);
  uv[3] = glm::vec2(right, bottom);
}

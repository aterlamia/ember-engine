//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_RENDERABLE_H
#define EMBER_CORE_RENDERABLE_H

#include <glm/glm.hpp>
#include <vector>
#include "Texture.h"

struct VertexData {
  glm::vec3 vertex;
  glm::vec2 texture_map;
//  unsigned int uv;
  glm::vec4 color;
};

class Renderable {
 private:
  glm::vec3 position;
  glm::vec4 color;
  glm::vec2 size;
  std::vector<glm::vec2> uv;
  Ember::Texture *texture = NULL;
 public:

  const std::vector<glm::vec2> &getUV() const;
 private:

  void setDefaultUV();
 public:

  Renderable();
  Renderable(
      const glm::vec3 &position,
      const glm::vec2 &size,
      Ember::Texture *texture
  );
  Renderable(
      const glm::vec3 &position,
      const glm::vec4 &color,
      const glm::vec2 &size
  );
  const glm::vec3 &getPosition() const;
  const glm::vec4 &getColor() const;
  const glm::vec2 &getSize() const;
  void setFrame(const glm::vec2 &position, const glm::vec2 &size);
};
#endif //EMBER_CORE_RENDERABLE_H

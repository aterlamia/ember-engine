//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Renderer.h"

Renderer::Renderer() {
  glGenVertexArrays(1, &vertexArray);
  glBindVertexArray(vertexArray);

  glGenBuffers(1, &vertextBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertextBuffer);
  glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

  glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
  glEnableVertexAttribArray(SHADER_TEXTURE_INDEX);
  glEnableVertexAttribArray(SHADER_COLOR_INDEX);

  glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid *) 0);

  glVertexAttribPointer(SHADER_TEXTURE_INDEX, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE,
                        (const GLvoid *)  offsetof(VertexData, VertexData::texture_map));

  glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE,
                        (const GLvoid *) offsetof(VertexData, VertexData::color));


  glBindBuffer(GL_ARRAY_BUFFER, 0);

  GLuint indices[RENDERER_INDICES_SIZE];

  int offset = 0;
  for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6) {
    indices[i] = offset;
    indices[i + 1] = offset + 1;
    indices[i + 2] = offset + 2;
    indices[i + 3] = offset + 2;
    indices[i + 4] = offset + 3;
    indices[i + 5] = offset;

    offset += 4;
  }


  indexBuffer = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
  glBindVertexArray(0);
}

Renderer::~Renderer() {
  delete indexBuffer;
  glDeleteBuffers(1, &vertextBuffer);

}

void Renderer::queue(const Renderable *renderable) {
  const glm::vec3 &position = renderable->getPosition();
  const glm::vec4 &color = renderable->getColor();
  const glm::vec2 &size = renderable->getSize();
  const std::vector<glm::vec2 >&texture = renderable->getUV();

  buffer->vertex = position;
  buffer->color = color;
  buffer->texture_map = texture[0];
  buffer++;

  buffer->vertex = glm::vec3(position.x, position.y + size.y, position.z);
  buffer->color = color;
  buffer->texture_map = texture[1];
  buffer++;

  buffer->vertex = glm::vec3(position.x + size.x, position.y + size.y, position.z);
  buffer->color = color;
  buffer->texture_map = texture[2];
  buffer++;

  buffer->vertex = glm::vec3(position.x + size.x, position.y, position.z);
  buffer->color = color;
  buffer->texture_map = texture[3];
  buffer++;

  indexCount += 6;
}

void Renderer::begin() {
  glBindBuffer(GL_ARRAY_BUFFER, vertextBuffer);
  buffer = (VertexData *) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void Renderer::end() {
  glUnmapBuffer(GL_ARRAY_BUFFER);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderer::draw() {
  glBindVertexArray(vertexArray);
  indexBuffer->enable();
  glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, NULL);
  indexBuffer->disable();
  glBindVertexArray(0);
  indexCount = 0;
}

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "IndexBuffer.h"

IndexBuffer::IndexBuffer() {
}

IndexBuffer::IndexBuffer(
    GLushort *data,
    GLsizei count
) : count(count) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::enable() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IndexBuffer::disable() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

GLuint IndexBuffer::getId() const {
  return id;
}

GLsizei IndexBuffer::getCount() const {
  return count;
}

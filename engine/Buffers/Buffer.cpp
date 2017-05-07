//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <GL/glew.h>
#include "Buffer.h"

Buffer::Buffer() {}

Buffer::Buffer(
    GLfloat *data,
    GLsizei count,
    Buffer::BufferType type
) : type(type), count(count) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ARRAY_BUFFER, id);
  glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::enable() {
  glBindBuffer(GL_ARRAY_BUFFER, id);
}

void Buffer::disable() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Buffer::BufferType Buffer::getType() const {
  return type;
}

GLuint Buffer::getId() const {
  return id;
}

GLsizei Buffer::getCount() const {
  return count;
}

Buffer::~Buffer() {
  glDeleteBuffers(1, &id);
}

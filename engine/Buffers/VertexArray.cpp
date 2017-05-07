//
// Created by Aterlamia.
// Part of the Ember-engine
//
#include "VertexArray.h"

VertexArray::VertexArray() {
}

void VertexArray::init() {
  glGenVertexArrays(1, &id);
}

VertexArray::~VertexArray() {
  for (int i = 0; i < buffers.size(); i++) {
    delete buffers[i];
  }
  glDeleteVertexArrays(1, &id);
}

void VertexArray::addBuffer(
    Buffer *buffer,
    GLuint index
) {
  enable();
  buffer->enable();

  glEnableVertexAttribArray(index);
  glVertexAttribPointer(index, buffer->getType(), GL_FLOAT, GL_FALSE, 0, 0);
  buffer->disable();
  disable();
}

void VertexArray::disable() {
  glBindVertexArray(0);
}

void VertexArray::enable() {
  glBindVertexArray(id);
}

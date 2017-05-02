//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_VERTEXARRAY_H
#define EMBER_CORE_VERTEXARRAY_H


#include <GL/glew.h>
#include <vector>
#include "Buffer.h"

class VertexArray {
  private:
    GLuint id;
    std::vector<Buffer *> buffers;
  public:
    VertexArray();
    virtual ~VertexArray();
    void addBuffer(Buffer *buffer, GLuint index);
    void enable();
    void disable();
    void init();
};


#endif //EMBER_CORE_VERTEXARRAY_H

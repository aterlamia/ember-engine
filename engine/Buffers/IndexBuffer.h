//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_INDEXBUFFER_H
#define EMBER_CORE_INDEXBUFFER_H

#include <GL/glew.h>

class IndexBuffer {
  public:
  private:
    GLuint id;
    GLsizei count;
  public:
    IndexBuffer();
    IndexBuffer(
        GLuint *data,
        GLsizei count
    );
    virtual ~IndexBuffer();
    void enable();
    void disable();
    GLuint getId() const;
    GLsizei getCount() const;
};


#endif //EMBER_CORE_INDEXBUFFER_H

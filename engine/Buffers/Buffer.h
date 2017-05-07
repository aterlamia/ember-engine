//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_BUFFER_H
#define EMBER_CORE_BUFFER_H


#include <SDL_opengl.h>

class Buffer {
  public:
    typedef enum {
      BUFFER_VEC2 = 2,
      BUFFER_VEC3 = 3,
      BUFFER_VEC4 = 4
    } BufferType;
  private:
    GLuint id;
    GLsizei count;
    BufferType type;
  public:
    virtual ~Buffer();
  public:
    Buffer();
    BufferType getType() const;
    Buffer(
        GLfloat *data,
        GLsizei count,
        BufferType type
    );
    void enable();
    void disable();
    GLuint getId() const;
    GLsizei getCount() const;
};


#endif //EMBER_CORE_BUFFER_H

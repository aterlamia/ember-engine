//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_RENDERER_H
#define EMBER_CORE_RENDERER_H


#include <Buffers/VertexArray.h>
#include <Buffers/IndexBuffer.h>
#include "Renderable.h"

#define RENDERER_MAX_SPRITES 20000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_TEXTURE_INDEX 1
#define SHADER_COLOR_INDEX 2

class Renderer {
  private:
    GLuint vertexArray;
    IndexBuffer *indexBuffer;
    GLuint vertextBuffer;
    GLsizei indexCount;
    VertexData *buffer;
  public:
    void begin();
    void end();
    void queue(const Renderable *renderable);
    void draw();
    Renderer();
    virtual ~Renderer();

};


#endif //EMBER_CORE_RENDERER_H

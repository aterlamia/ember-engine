//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_RENDERER_H
#define EMBER_CORE_RENDERER_H


#include "Renderable.h"

class Renderer {
  public:
    void queue(Renderable renderable);
    void draw();
};


#endif //EMBER_CORE_RENDERER_H

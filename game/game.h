//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_GAME_H
#define EMBER_CORE_GAME_H


#include <Display/Window.h>
#include <tools/fps.h>
#include <Graphical/Shader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Game {
  private:
    bool isRunning = false;
    int windowHeight, windowWidth;

    Ember::Window *window;
    Fps *fps;
    Shader *shader;
  public:
    bool init();
    void run();
    void handleEvents();
    Game(
        int windowHeight,
        int windowWidth
    );
    void initShaders();
};


#endif //EMBER_CORE_GAME_H

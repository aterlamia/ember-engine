//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_GAME_H
#define EMBER_CORE_GAME_H


#include <Display/Window.h>
#include <Graphical/Shader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Tools/fps.h>

class Game {
  private:
    bool isRunning = false;
    float ratio;
    int windowHeight, windowWidth;
    float asepectHeight;
    float aspectWidth;

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
    float gcd(
        float width,
        float height
    );
    void setProjectionMatrix();
};


#endif //EMBER_CORE_GAME_H

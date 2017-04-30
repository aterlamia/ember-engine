
#include <Display/Window.h>
#include <Graphical/Shader.h>
#include <iostream>
#include <tools/helpers.h>

#define GL3_PROTOTYPES 1
#include <GL/glew.h>
#include <SDL2/SDL.h>

int main() {

  Ember::Window *window = new Ember::Window(600, 600, "TST");
  bool isRunning;

  if (window->init()) {
    isRunning = true;
  } else {
    SDL_Log("Something failed");
  }

//  helpers::printSDL_GL_Attributes();

  GLfloat vertices[] = {
      -0.5f, -0.5f, 0.0f,
      -0.5f, 0.5f, 0.0f,
      0.5f, 0.5f, 0.0f,
      0.5f, 0.5f, 0.0f,
      0.5f, -0.5f, 0.0f,
      -0.5f, -0.5f, 0.0f
  };

  GLuint vertexArray;
  glGenVertexArrays(1, &vertexArray);
  glBindVertexArray(vertexArray);

  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);


  SDL_Log("Loading shaders");
  Shader shader("files/shaders/base.vert", "files/shaders/base.frag");
  shader.on();
  SDL_Event event;

  SDL_Log("Starting game loop");
  while (isRunning) {
    window->clear();

    while (SDL_PollEvent(&event)) {

      switch (event.type) {
        case SDL_QUIT:
          isRunning = false;
          break;
        default:
          break;
      }

      if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
          case SDLK_ESCAPE:
            isRunning = false;
            break;
          default:
            break;
        }
      }
      if (event.type == SDL_WINDOWEVENT) {
        window->handleEvents(event);
      }
    }
    glDrawArrays(GL_TRIANGLES, 0, 6);

    window->update();
  }
  return 0;
}

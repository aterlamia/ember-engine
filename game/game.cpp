//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <Buffers/VertexArray.h>
#include <Buffers/IndexBuffer.h>
#include "game.h"

void Game::run() {

  SDL_Log("Loading shaders");
  shader = new Shader("files/shaders/base.vert", "files/shaders/base.frag");
  shader->on();
  glm::mat4 projection = glm::ortho(0.0f, 120.0f, 0.0f, 90.0f, -1.0f, 1.0f);
  glUniformMatrix4fv(glGetUniformLocation(shader->getShaderId(), "pr_matrix"), 1, GL_FALSE, value_ptr(projection));

  glm::mat4 translation = translate(glm::mat4(), glm::vec3(0, 0, 0));
  glUniformMatrix4fv(glGetUniformLocation(shader->getShaderId(), "ml_matrix"), 1, GL_FALSE, value_ptr(translation));

  glUniform2f(glGetUniformLocation(shader->getShaderId(), "light_pos"), 4.5f, 4.5f);
  glUniform4f(glGetUniformLocation(shader->getShaderId(), "colour"), 1.0f, 0.3f, 1.0f, 0.5f);

  GLfloat vertices[] = {
      0, 0, 0,
      0, 10, 0,
      10, 10, 0,
      10, 0, 0,
  };

  GLushort indices[] = {
      0, 1, 2,
      2, 3, 0
  };

  GLfloat color[]{
      1, 0, 1, 1,
      1, 0, 1, 1,
      1, 0, 1, 1,
      1, 0, 1, 1,
  };

  GLfloat colorb[]{
      1, 0, 0.5f, 1,
      0.5f, 0, 1, 1,
      1, 0.5f, 1, 1,
      1, 0, 0.5f, 1,
  };

  VertexArray vertexArray, vertexArray2;
  IndexBuffer indexBuffer(indices, 6);

  vertexArray.init();
  vertexArray.addBuffer(new Buffer(vertices, 16, Buffer::BUFFER_VEC3), 0);
  vertexArray.addBuffer(new Buffer(color, 16, Buffer::BUFFER_VEC4), 1);

  vertexArray2.init();
  vertexArray2.addBuffer(new Buffer(vertices, 16, Buffer::BUFFER_VEC3), 0);
  vertexArray2.addBuffer(new Buffer(colorb, 16, Buffer::BUFFER_VEC4), 1);

  SDL_Log("Starting game loop");
  while (isRunning) {
    window->clear();

    vertexArray.enable();
    indexBuffer.enable();
    translation = translate(glm::mat4(), glm::vec3(0, 0, 0));
    glUniformMatrix4fv(glGetUniformLocation(shader->getShaderId(), "ml_matrix"), 1, GL_FALSE,
                       value_ptr(translation));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
    indexBuffer.disable();
    vertexArray.disable();

    vertexArray2.enable();
    indexBuffer.enable();
    translation = translate(glm::mat4(), glm::vec3(10, 0, 0));

    glUniformMatrix4fv(glGetUniformLocation(shader->getShaderId(), "ml_matrix"), 1, GL_FALSE,
                       value_ptr(translation));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
    indexBuffer.disable();
    vertexArray2.disable();
//
    window->update();

    handleEvents();
    // For now just a cout
    fps->update();
    fps->Render();
  }
}

bool Game::init() {
  fps = new Fps();

  window = new Ember::Window(windowHeight, windowWidth, "TST");

  if (window->init()) {
    isRunning = true;
  } else {
    SDL_Log("Something failed");
    return false;
  }

  initShaders();

  return true;
}


void Game::initShaders() {


}

Game::Game(
    int windowWidth,
    int windowHeight
) : windowHeight(windowHeight)
    , windowWidth(windowWidth) {}

void Game::handleEvents() {
  SDL_Event event;

  int x, y;
  while (SDL_PollEvent(&event)) {

    switch (event.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
      case SDL_MOUSEMOTION:
        SDL_GetMouseState(&x, &y);
        glUniform2f(
            glGetUniformLocation(
                shader->getShaderId(),
                "light_pos"
            ),
            float(x * 120.0f / 1024.0f),
            float(90.0f - y * 90.0f / 768.0f));
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
}


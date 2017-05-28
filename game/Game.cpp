//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <Buffers/VertexArray.h>
#include <Graphical/Renderer.h>
#include "Game.h"
#include <glm/ext.hpp>
#include <tools/ToString.h>
void Game::run() {

  SDL_Log("Loading shaders");
  shader = new Shader("files/shaders/base.vert", "files/shaders/base.frag");
  shader->on();

  glm::mat4 projection = glm::ortho(0.0f, (float) windowWidth, (float) windowHeight, 0.0f, 1.0f, -1.0f);

  glUniformMatrix4fv(glGetUniformLocation(shader->getShaderId(), "pr_matrix"), 1, GL_FALSE, value_ptr(projection));
  glUniform1i(glGetUniformLocation(shader->getShaderId(), "textureMap"), 0);

  glActiveTexture(GL_TEXTURE0);
  Ember::Texture texture("files/assets/groundtile.png");
  texture.bind();

  std::vector<Renderable *> sprites;

  for (int i = 0; i < windowHeight; i += 16) {
    for (int j = 0; j < windowWidth; j += 16) {
      Renderable *renderable = new Renderable(glm::vec3(i, j, 0),
                                              glm::vec2(16.0f, 16.0f),
                                              &texture
      );
      renderable->setFrame(glm::vec2(i, j), glm::vec2(16.0f, 16.0f));
      sprites.push_back(renderable);
    }
  }
  Renderer renderer;
  glUniform2f(glGetUniformLocation(shader->getShaderId(), "light_pos"), 4.5f, 4.5f);
  std::cout << "NUMBER OF SPRITES = " << sprites.size() << std::endl;
  SDL_Log("Starting game loop");

  while (isRunning) {
    window->clear();
    renderer.begin();
    for (int i = 0; i < sprites.size(); i++) {
      renderer.queue(sprites[i]);
    }

    renderer.end();
    renderer.draw();

    window->update();

    handleEvents();
    fps->update();
    fps->Render();
  }
}

void Game::setProjectionMatrix() {
  windowWidth = window->getWindowWidth();
  windowHeight = window->getWindowHeight();
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

  return true;
}

Game::Game(
    int windowWidth,
    int windowHeight
) : windowHeight(windowHeight), windowWidth(windowWidth) {
  ratio = gcd(windowWidth, windowHeight);
}

void Game::handleEvents() {
  SDL_Event event;

  int x, y;
  while (SDL_PollEvent(&event)) {

    switch (event.type) {
      case SDL_QUIT:isRunning = false;
        break;
      case SDL_MOUSEMOTION:SDL_GetMouseState(&x, &y);
        glUniform2f(
            glGetUniformLocation(
                shader->getShaderId(),
                "light_pos"
            ),
            float(x * aspectWidth / (float) windowWidth),
            float(asepectHeight - y * asepectHeight / (float) windowHeight));
        break;
      default:break;
    }

    if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:isRunning = false;
          break;
        default:break;
      }
    }
    if (event.type == SDL_WINDOWEVENT) {
      window->handleEvents(event);
      if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
        setProjectionMatrix();
      }
    }
  }
}

float Game::gcd(
    float width,
    float height
) {
  if (height == 0.0f) {
    return width;
  } else {
    return gcd(height, fmod(width, height));
  }
}



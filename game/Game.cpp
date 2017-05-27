//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <Buffers/VertexArray.h>
#include <Graphical/Renderer.h>
#include <Graphical/Texture.h>
#include "Game.h"

void Game::run() {

  SDL_Log("Loading shaders");
  shader = new Shader("files/shaders/base.vert", "files/shaders/base.frag");
  shader->on();

  glm::mat4 projection = glm::ortho(0.0f, aspectWidth, 0.0f, asepectHeight, -1.0f, 1.0f);
  glUniformMatrix4fv(glGetUniformLocation(shader->getShaderId(), "pr_matrix"), 1, GL_FALSE, value_ptr(projection));
  glUniform1i(glGetUniformLocation(shader->getShaderId(), "textureMap"), 0);

  glActiveTexture(GL_TEXTURE0);
  Ember::Texture texture("files/texture/test.png");
  texture.bind();

  std::vector<Renderable *> sprites;

  sprites.push_back(new Renderable(glm::vec3(20, 20, 0),
                                   glm::vec2(40.0f, 40.0f),
                                   &texture
  ));


//  for (float i = 0; i < 70.0f; i += 0.5f) {
//    for (float j = 0; j < 80.0f; j += 0.5f) {
//      sprites.push_back(new Renderable(glm::vec3(i, j, 0),
//                                       glm::vec4(rand() % 1000 / 1000.0f, rand() % 1000 / 999.0f, 1, 1),
//                                       glm::vec2(0.5f, 0.5f)));
//    }
//  }
  Renderer renderer;
  glUniform2f(glGetUniformLocation(shader->getShaderId(), "light_pos"), 4.5f, 4.5f);
  std::cout << "NUMBER OF SPRITES = " << sprites.size() << std::endl;
  SDL_Log("Starting game loop");

  int frame = 3;
  while (isRunning) {
    window->clear();
    renderer.begin();

    for (int i = 0; i < sprites.size(); i++) {
      renderer.queue(sprites[i]);
      sprites[0]->setFrame(glm::vec2(0, frame * 71.0f), glm::vec2(71.0f, 71.0f));
    }
    renderer.end();
    renderer.draw();

    window->update();

//    frame++;
    if (frame > 3) {
      frame = 0;
    }

    handleEvents();
    // For now just a cout
    fps->update();
    fps->Render();
  }
}

void Game::setProjectionMatrix() {
  windowWidth = window->getWindowWidth();
  windowHeight = window->getWindowHeight();
  ratio = gcd((float) windowWidth, (float) windowHeight);
  aspectWidth = (((float) windowWidth) / ratio) * 20.0f;
  asepectHeight = (((float) windowHeight) / ratio) * 20.0f;

  std::cout << "(" << windowWidth << "," << windowHeight << ") : [" << aspectWidth << ", " << asepectHeight << "] --- "
            << ratio << std::endl;
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
  aspectWidth = (windowWidth / ratio) * 20.0f;
  asepectHeight = (windowHeight / ratio) * 20.0f;
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



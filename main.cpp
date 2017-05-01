
#include <Display/Window.h>
#include <Graphical/Shader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main() {


  /// ================== TEST code here =====================

  // ===================== End test code ===============

  Ember::Window *window = new Ember::Window(1000, 1000, "TST");

  bool isRunning;

  if (window->init()) {
    isRunning = true;
  } else {
    SDL_Log("Something failed");
  }

  GLfloat vertices[] = {
      0, 0, 0,
      3, 0, 0,
      0, 3, 0,
      0, 3, 0,
      3, 3, 0,
      3, 0, 0
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

  glm::mat4 projection = glm::ortho(0.0f, 16.0f, 0.0f, 16.0f, -1.0f, 1.0f);
  glm::mat4 translation = glm::translate(glm::mat4(), glm::vec3(3, 3, 0));
  glUniformMatrix4fv(glGetUniformLocation(shader.getShaderId(), "pr_matrix"), 1, GL_FALSE, glm::value_ptr(projection));
  glUniformMatrix4fv(glGetUniformLocation(shader.getShaderId(), "ml_matrix"), 1, GL_FALSE, glm::value_ptr(translation));

  glUniform2f(glGetUniformLocation(shader.getShaderId(), "light_pos"), 4.5f, 4.5f);
  glUniform4f(glGetUniformLocation(shader.getShaderId(), "colour"), 0.2f, 0.3f, 0.8f, 1.0f);
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

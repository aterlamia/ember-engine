
#include <Display/Window.h>
#include <Graphical/Shader.h>
#include <Math/Matrix.h>
#include <iostream>
#include <Math/Vector2D.h>
#include <Math/Vector4D.h>

#define GL3_PROTOTYPES 1

int main() {


  /// ================== TEST code here =====================

  Vector2D vec2 = Vector2D(1, 2);
  Vector3D vec3 = Vector3D(1, 2, 3);
  Vector4D vec4 = Vector4D(1, 2, 3, 4);
  Matrix init1 = Matrix();
  Matrix init2 = Matrix(12.0f);
  Matrix identity = Matrix::identity();
  Matrix ortho = Matrix::orthograpic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
  Matrix pers = Matrix::perspective(10, 6, 1, 2);

  std::cout << vec2;
  std::cout << vec3;
  std::cout << vec4;
  std::cout << "\nWithout float\n\n";
  std::cout << init1;
  std::cout << "\nWith float\n\n";
  std::cout << init2;
  std::cout << "\nIdentity\n\n";
  std::cout << identity;
  std::cout << "\nOrtho\n\n";
  std::cout << ortho;
  std::cout << "\nPerspective\n\n";
  std::cout << pers;
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
      8, 0, 0,
      0, 3, 0,
      0, 3, 0,
      8, 3, 0,
      8, 0, 0
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

  Matrix projection = Matrix::orthograpic(0.0f, 16.0f, 0.0f, 9.0f, 1.0f, -1.0f);
  glUniformMatrix4fv(glGetUniformLocation(shader.getShaderId(), "pr_matrix"), 1, GL_FALSE, ortho.elements);

  glUniform2f(glGetUniformLocation(shader.getShaderId(), "light_pos"), 3, 3);
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

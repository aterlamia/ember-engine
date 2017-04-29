
#include <Display/Window.h>
#include <SDL_opengl.h>
#include <iostream>

int main() {

  Ember::Window *window = new Ember::Window(600, 600, "TST");
  bool isRunning;

  if (window->init()) {
    isRunning = true;
  } else {
    std::cout << "Something failed\n";
  }


  SDL_Event event;

  while (isRunning) {
    window->clear();

    while (SDL_PollEvent(&event)) {

      switch (event.type) {
        case SDL_QUIT:
          isRunning = false;
          break;
        case SDL_WINDOWEVENT_RESIZED:
          std::cout << "!!!!!\n";
          window->resize(event.window.data1, event.window.data2);
          break; // resizing called here
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

    glBegin(GL_QUADS);
    glVertex2d(-0.5f, -0.5f);
    glVertex2d(0.0f, 0.5f);
    glVertex2d(-0.5f, 0.0f);
    glVertex2d(0.5f, 0.5f);
    glEnd();
    window->update();
  }
  return 0;
}
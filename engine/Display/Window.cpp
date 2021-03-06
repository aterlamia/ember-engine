//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <iostream>
#include "Window.h"

namespace Ember {

  void Window::update() const {
    glClearColor(0.2, 0.2, 0.2, 0.2);
    SDL_GL_SwapWindow(window);
  }

  int Window::getWindowHeight() const {
    return windowHeight;
  }

  int Window::getWindowWidth() const {
    return windowWidth;
  }

  void Window::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
  }

  bool Window::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      std::cout << "Error on line " << __LINE__ << " in " __FILE__ << " WITH " << SDL_GetError() << std::endl;
      return false;
    }

    window = SDL_CreateWindow(
        title, 0, 0, windowWidth, windowHeight,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    //Initialize OpenGL
    if (!initGL()) {
      printf("Unable to initialize OpenGL!\n");
      return false;
    }

    SDL_Log("SDL succesfull inited ");
    SDL_Log("Creating context ");
    context = SDL_GL_CreateContext(window);
    if (context == NULL) {
      printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
    } else {
      //Use Vsync
//      if (SDL_GL_SetSwapInterval(1) < 0) {
//        printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
//      } else {
//        SDL_Log("Vsync enabled");
//      }
      SDL_GL_SetSwapInterval(0);
    }
    glewExperimental = GL_TRUE;
    glewInit();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
  }


  bool Window::initGL() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


    return true;
  }

  Window::Window(
      int windowHeight,
      int windowWidth,
      const char *title
  ) : windowHeight(windowHeight)
      , windowWidth(windowWidth)
      , title(title) {}

  void Window::resize(
      Sint32 screen_width,
      Sint32 screen_height
  ) {

    windowHeight = screen_height;
    windowWidth = screen_width;
    glViewport(0, 0, windowWidth, windowHeight);
  }

  void Window::handleEvents(SDL_Event event) {
    switch (event.window.event) {
      case SDL_WINDOWEVENT_SHOWN:
        SDL_Log("Window %d shown", event.window.windowID);
        break;
      case SDL_WINDOWEVENT_HIDDEN:
        SDL_Log("Window %d hidden", event.window.windowID);
        break;
      case SDL_WINDOWEVENT_EXPOSED:
        SDL_Log("Window %d exposed", event.window.windowID);
        break;
      case SDL_WINDOWEVENT_MOVED:
        SDL_Log("Window %d moved to %d,%d",
                event.window.windowID, event.window.data1,
                event.window.data2);
        break;
      case SDL_WINDOWEVENT_RESIZED:
        resize(event.window.data1, event.window.data2);
        windowWidth = event.window.data1;
        windowHeight = event.window.data2;

        SDL_Log("Window %d resized to %dx%d",
                event.window.windowID, event.window.data1,
                event.window.data2);
        break;
      case SDL_WINDOWEVENT_SIZE_CHANGED:
        resize(event.window.data1, event.window.data2);
        windowWidth = event.window.data1;
        windowHeight = event.window.data2;

        break;
      case SDL_WINDOWEVENT_MINIMIZED:
        SDL_Log("Window %d minimized", event.window.windowID);
        break;
      case SDL_WINDOWEVENT_MAXIMIZED:
        SDL_Log("Window %d maximized", event.window.windowID);
        break;
      case SDL_WINDOWEVENT_RESTORED:
        SDL_Log("Window %d restored", event.window.windowID);
        break;
      case SDL_WINDOWEVENT_ENTER:
        SDL_Log("Mouse entered window %d",
                event.window.windowID);
        break;
      case SDL_WINDOWEVENT_LEAVE:
        SDL_Log("Mouse left window %d", event.window.windowID);
        break;
      case SDL_WINDOWEVENT_FOCUS_GAINED:
        SDL_Log("Window %d gained keyboard focus",
                event.window.windowID);
        break;
      case SDL_WINDOWEVENT_FOCUS_LOST:
        SDL_Log("Window %d lost keyboard focus",
                event.window.windowID);
        break;
      case SDL_WINDOWEVENT_CLOSE:
        SDL_Log("Window %d closed", event.window.windowID);
        break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
      case SDL_WINDOWEVENT_TAKE_FOCUS:
        SDL_Log("Window %d is offered a focus", event.window.windowID);
        break;
      case SDL_WINDOWEVENT_HIT_TEST:
        SDL_Log("Window %d has a special hit test", event.window.windowID);
        break;
#endif
      default:
        SDL_Log("Window %d got unknown event %d",
                event.window.windowID, event.window.event);
        break;
    }
  }

}
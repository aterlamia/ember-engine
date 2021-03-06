//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_WINDOW_H
#define EMBER_CORE_WINDOW_H

#include <string>
#include <GL/glew.h>
#include <SDL.h>

namespace Ember {
  class Window {
    private :
      int windowHeight, windowWidth;
      const char *title;
      SDL_Window *window = 0;
      SDL_GLContext context = 0;
    public:
      virtual ~Window() {};
      Window(
          int windowHeight,
          int windowWidth,
          const char *title
      );

      bool init();



      void update() const;
      void clear() const;
    private :

      bool initGL();
    public:
      void resize(
          Sint32 i,
          Sint32 i1
      );
      void handleEvents(SDL_Event event);
      int getWindowHeight() const;
      int getWindowWidth() const;
  };
};

#endif //EMBER_CORE_WINDOW_H

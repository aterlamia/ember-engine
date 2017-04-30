//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include "helpers.h"
void helpers::printSDL_GL_Attributes()
{
  int value = 0;
  SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &value);
  std::cout << "SDL_GL_CONTEXT_MAJOR_VERSION : " << value << std::endl;

  SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &value);
  std::cout << "SDL_GL_CONTEXT_MINOR_VERSION: " << value << std::endl;

  std::cout <<  glGetString(GL_VENDOR) << "\n";
  std::cout <<  glGetString(GL_RENDERER) << "\n";
  std::cout <<  glGetString(GL_VERSION) << "\n";
  std::cout <<  glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";

}
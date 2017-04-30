//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <GLES2/gl2.h>
#include <tools/file.h>
#include <vector>
#include <SDL_log.h>
#include "Shader.h"

Shader::Shader(
    const char *vertShaderPath,
    const char *fragShaderPath
) {
  shaderProgram = glCreateProgram();

  vertextShader = glCreateShader(GL_VERTEX_SHADER);
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  try {
    loadShader(vertShaderPath, vertextShader);
    loadShader(fragShaderPath, fragmentShader);
  }
  catch (const std::runtime_error &e) {
    std::cerr << e.what() << "\n";
  }

  glAttachShader(shaderProgram, vertextShader);
  glAttachShader(shaderProgram, fragmentShader);

  glLinkProgram(shaderProgram);
  glValidateProgram(shaderProgram);

  glDeleteShader(vertextShader);
  glDeleteShader(fragmentShader);
}

void Shader::loadShader(
    const char *path,
    GLuint shader
) {
  std::string shaderContent = getFileContents(path);
  const char *shaderString = shaderContent.c_str();

  GLint result;
  glShaderSource(shader, 1, &shaderString, NULL);
  glCompileShader(shader);
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

  if (result == GL_FALSE) {
    GLint lenght;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &lenght);
    std::vector<char> error(lenght);
    glGetShaderInfoLog(shader, lenght, &lenght, &error[0]);
    glDeleteShader(shader);

    std::cout << path << "\n";
    throw std::runtime_error(&error[0]);
  }
}

void Shader::on() const {
  glUseProgram(shaderProgram);
}

void Shader::off() const {
  glUseProgram(0);
}

Shader::~Shader() {
  glDeleteProgram(shaderProgram);
}

GLuint Shader::getShaderId() {
  return shaderProgram;
}

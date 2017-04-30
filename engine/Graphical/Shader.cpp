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


//  LinkShaders();
  glLinkProgram(shaderProgram);
  glValidateProgram(shaderProgram);

//  glDeleteShader(vertextShader);
//  glDeleteShader(fragmentShader);
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

    PrintShaderCompilationErrorInfo(shader);

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

bool Shader::LinkShaders() {
  // Link. At this point, our shaders will be inspected/optized and the binary code generated
  // The binary code will then be uploaded to the GPU
  glLinkProgram(shaderProgram);

  // Verify that the linking succeeded
  int isLinked;
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, (int *) &isLinked);

  if (isLinked == false)
    PrintShaderLinkingError(shaderProgram);

  return isLinked != 0;
}

void Shader::PrintShaderLinkingError(int32_t shaderId) {
  std::cout << "=======================================\n";
  std::cout << "Shader linking failed : " << std::endl;

  // Find length of shader info log
  int maxLength;
  glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

  std::cout << "Info Length : " << maxLength << std::endl;

  // Get shader info log
  char *shaderProgramInfoLog = new char[maxLength];
  glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, shaderProgramInfoLog);

  std::cout << "Linker error message : " << shaderProgramInfoLog << std::endl;

  /* Handle the error in an appropriate way such as displaying a message or writing to a log file. */
  /* In this simple program, we'll just leave */
  delete shaderProgramInfoLog;
  return;
}

// If something went wrong whil compiling the shaders, we'll use this function to find the error
void Shader::PrintShaderCompilationErrorInfo(int32_t shaderId) {
  std::cout << "=======================================\n";
  std::cout << "Shader compilation failed : " << std::endl;

  // Find length of shader info log
  int maxLength;
  glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

  // Get shader info log
  char *shaderInfoLog = new char[maxLength];
  glGetShaderInfoLog(shaderId, maxLength, &maxLength, shaderInfoLog);

  // Print shader info log
  std::cout << "\tError info : " << shaderInfoLog << std::endl;

  std::cout << "=======================================\n\n";
  delete shaderInfoLog;
}

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBER_CORE_SHADER_H
#define EMBER_CORE_SHADER_H

class Shader {
  private:
    GLuint shaderProgram;

  public:
    virtual ~Shader();
    Shader(
        const char *vertShaderPath,
        const char *fragShaderPath
    );

    void on() const;
    void off() const;
  private:
    void loadShader(
        const char *path,
        GLuint shader
    );
    void PrintShaderCompilationErrorInfo(int32_t shaderId);
    void PrintShaderLinkingError(int32_t shaderId);
    bool LinkShaders();
    GLuint vertextShader;
    GLuint fragmentShader;
};


#endif //EMBER_CORE_SHADER_H

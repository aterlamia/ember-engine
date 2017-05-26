//
// Created by melvin on 22-5-17.
//

#ifndef EMBER_CORE_TEXTURE_H
#define EMBER_CORE_TEXTURE_H

#include <GL/glew.h>
#include <string>
namespace Ember {
class Texture {
 private:
  std::string m_FileName;
  GLuint m_TID;
  GLsizei m_Width, m_Height;
 public:
  Texture(const std::string &filename);
  ~Texture();
  void bind() const;
  void unbind() const;

  inline const unsigned int getWidth() const { return m_Width; }
  inline const unsigned int getHeight() const { return m_Height; }
 private:
  GLuint load();
};
};

#endif //EMBER_CORE_TEXTURE_H

//
// Created by melvin on 22-5-17.
//

#ifndef EMBER_CORE_IMAGELOADER_H
#define EMBER_CORE_IMAGELOADER_H
#include <FreeImage.h>
#include <GL/glew.h>
namespace Ember {
  static BYTE *load_image(const char *filename, GLsizei *width, GLsizei *height) {
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
    FIBITMAP *dib = nullptr;
    fif = FreeImage_GetFileType(filename, 0);
    if (fif == FIF_UNKNOWN)
      fif = FreeImage_GetFIFFromFilename(filename);
    if (fif == FIF_UNKNOWN)
      return nullptr;

    if (FreeImage_FIFSupportsReading(fif))
      dib = FreeImage_Load(fif, filename);
    if (!dib)
      return nullptr;

    BYTE *result = FreeImage_GetBits(dib);
    *width = FreeImage_GetWidth(dib);
    *height = FreeImage_GetHeight(dib);

    return result;
  }
}

#endif //EMBER_CORE_IMAGELOADER_H

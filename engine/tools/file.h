//
// Created by Aterlamia.
// Part of the Ember-engine
//

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>


#ifndef EMBER_CORE_FILE_H
#define EMBER_CORE_FILE_H

std::string getFileContents(const char *filename) {
  std::ifstream in(filename, std::ios::in | std::ios::binary);

  if (in) {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return (contents);
  }
  throw (errno);
}


#endif //EMBER_CORE_FILE_H

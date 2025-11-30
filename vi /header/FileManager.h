#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "TextBuffer.h"
#include <string>

bool loadFile(const std::string&, TextBuffer&);
bool saveFile(const std::string&, const TextBuffer&);

std::string readAll(const std::string&);

#endif

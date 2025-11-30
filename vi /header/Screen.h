#ifndef SCREEN_H
#define SCREEN_H

#include "EditorState.h"
#include <string>

namespace Screen {

void drawEditor(const EditorState&);
void drawDisplay(const std::string&);
void drawHome();

}

#endif

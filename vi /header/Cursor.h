#ifndef CURSOR_H
#define CURSOR_H

#include "TextBuffer.h"

struct Cursor {
    int x;
    int y;
};

void cursorLeft(Cursor&, const TextBuffer&);
void cursorRight(Cursor&, const TextBuffer&);
void cursorUp(Cursor&, const TextBuffer&);
void cursorDown(Cursor&, const TextBuffer&);

#endif

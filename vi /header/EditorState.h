#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "TextBuffer.h"
#include "Cursor.h"

struct EditorState {
    TextBuffer buffer;
    Cursor cursor;
};

void initEditor(EditorState&);
void freeEditor(EditorState&);

void editorInsertChar(EditorState&, char);
void editorBackspace(EditorState&);
void editorEnter(EditorState&);

void editorMoveLeft(EditorState&);
void editorMoveRight(EditorState&);
void editorMoveUp(EditorState&);
void editorMoveDown(EditorState&);

#endif

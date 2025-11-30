#include "../header/EditorState.h"

void initEditor(EditorState& e) {
    initBuffer(e.buffer);
    e.cursor.x = 0;
    e.cursor.y = 0;
}

void freeEditor(EditorState& e) {
    freeBuffer(e.buffer);
}

void editorInsertChar(EditorState& e, char c) {
    insertChar(e.buffer, e.cursor.y, e.cursor.x, c);
    e.cursor.x++;
}

void editorBackspace(EditorState& e) {
    if (e.cursor.x > 0) {
        deleteChar(e.buffer, e.cursor.y, e.cursor.x);
        e.cursor.x--;
    } else if (e.cursor.y > 0) {
        int prevLen = e.buffer.lineLen[e.cursor.y - 1];
        mergeLineUp(e.buffer, e.cursor.y);
        e.cursor.y--;
        e.cursor.x = prevLen;
    }
}

void editorEnter(EditorState& e) {
    splitLine(e.buffer, e.cursor.y, e.cursor.x);
    e.cursor.y++;
    e.cursor.x = 0;
}

void editorMoveLeft(EditorState& e) { cursorLeft(e.cursor, e.buffer); }
void editorMoveRight(EditorState& e) { cursorRight(e.cursor, e.buffer); }
void editorMoveUp(EditorState& e) { cursorUp(e.cursor, e.buffer); }
void editorMoveDown(EditorState& e) { cursorDown(e.cursor, e.buffer); }

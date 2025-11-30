#include "../header/Cursor.h"

void cursorLeft(Cursor& c, const TextBuffer& b) {
    if (c.x > 0) c.x--;
    else if (c.y > 0) {
        c.y--;
        c.x = b.lineLen[c.y];
    }
}

void cursorRight(Cursor& c, const TextBuffer& b) {
    if (c.x < b.lineLen[c.y]) c.x++;
    else if (c.y < b.lineCount - 1) {
        c.y++;
        c.x = 0;
    }
}

void cursorUp(Cursor& c, const TextBuffer& b) {
    if (c.y > 0) {
        c.y--;
        if (c.x > b.lineLen[c.y]) c.x = b.lineLen[c.y];
    }
}

void cursorDown(Cursor& c, const TextBuffer& b) {
    if (c.y < b.lineCount - 1) {
        c.y++;
        if (c.x > b.lineLen[c.y]) c.x = b.lineLen[c.y];
    }
}

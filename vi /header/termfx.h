#ifndef TERMFX_H
#define TERMFX_H

#include <string>

// ======== COLOR ENUM =========
enum class Color {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,

    BrightBlack = 90,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightBlue = 94,
    BrightMagenta = 95,
    BrightCyan = 96,
    BrightWhite = 97
};

// ======== KEYS =========
enum class Key {
    Char,
    Enter,
    Backspace,
    Left, Right, Up, Down,
    Escape,
    Home,
    End,
    Unknown
};

// ======== RAW MODE =========
void enableRaw();
void disableRaw();

// ======== INPUT HANDLING =========
Key getKey(char* out);

// ======== OUTPUT =========
void clear();
void moveCursor(int x, int y);
void showCursor();
void hideCursor();

void setColor(Color c);
void resetColor();

int getConsoleWidth();
int getConsoleHeight();

#endif

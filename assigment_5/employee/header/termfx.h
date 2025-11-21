#ifndef TERMFX_HPP
#define TERMFX_HPP

#include <string>
#include <vector>

// Color enumeration (cross-platform)
enum class Color {
    Default = 0,

    // ANSI / Linux colors
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,

    // Bright colors (optional)
    BrightBlack = 90,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightBlue = 94,
    BrightMagenta = 95,
    BrightCyan = 96,
    BrightWhite = 97
};

// Key codes for keyboard input
enum class Key {
    Up,
    Down,
    Left,
    Right,
    Enter,
    Escape,
    Home,
    End,
    Backspace,
    Unknown
};

// Basic terminal functions
void moveCursor(int x, int y);
void setColor(Color color);
void resetColor();
void printAt(int x, int y, const std::string& text, Color color = Color::White);
void clear();
void delay(int milliseconds);
Key getKey();
void hideCursor();
void showCursor();
int getConsoleWidth();
int getConsoleHeight();

// Helper functions
void clearInputBuffer();
void showBackButton();

// Menu drawing function
void drawMenu(const char* items[], int size, int selected);

#endif
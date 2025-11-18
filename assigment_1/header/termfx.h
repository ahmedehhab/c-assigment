#ifndef TERMFX_HPP
#define TERMFX_HPP

#include <string>

// namespace termfx {

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

    // Move the cursor to position (x, y)
    void moveCursor(int x, int y);

    // Set text color
    void setColor(Color color);

    // Reset text color to default
    void resetColor();

    // Print text at specific position with color
    void printAt(int x, int y, const std::string& text, Color color);
    void clear();                       
     void delay(int milliseconds); 

// } // namespace termfx

#endif

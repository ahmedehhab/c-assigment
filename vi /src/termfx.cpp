#include "../header/termfx.h"
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

static termios oldSettings;

// =========================
// RAW MODE
// =========================

void enableRaw() {
    termios t;
    tcgetattr(STDIN_FILENO, &oldSettings);
    t = oldSettings;

    t.c_lflag &= ~(ICANON | ECHO);
    t.c_iflag &= ~IXON;

    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void disableRaw() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
}

// =========================
// COLOR
// =========================

void setColor(Color c) {
    std::cout << "\033[" << (int)c << "m";
}

void resetColor() {
    std::cout << "\033[0m";
}

// =========================
// CLEAR + CURSOR
// =========================

void clear() {
    std::cout << "\033[2J\033[H";
}

void moveCursor(int x, int y) {
    std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
}

void showCursor() {
    std::cout << "\033[?25h";
}

void hideCursor() {
    std::cout << "\033[?25l";
}

// =========================
// INPUT HANDLING
// =========================

Key getKey(char* out) {
    char c;
    if (read(STDIN_FILENO, &c, 1) <= 0) return Key::Unknown;

    *out = c;

    if (c == 27) { // ESC or arrow
        char seq[2];
        if (read(STDIN_FILENO, &seq[0], 1) == 0) return Key::Escape;
        if (read(STDIN_FILENO, &seq[1], 1) == 0) return Key::Escape;

        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': return Key::Up;
                case 'B': return Key::Down;
                case 'C': return Key::Right;
                case 'D': return Key::Left;
            }
        }
        return Key::Escape;
    }

    if (c == 127 || c == 8) return Key::Backspace; 
    if (c == '\r' || c == '\n') return Key::Enter;

    return Key::Char;
}
int getConsoleWidth() {

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int getConsoleHeight() {

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;

}
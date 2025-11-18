#include "../header/termfx.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdio>
#include <unistd.h>  // for usleep
#endif

// namespace termfx {

void moveCursor(int x, int y) {
#ifdef _WIN32
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y + 1, x + 1);
#endif
}

void setColor(Color color) {
#ifdef _WIN32
    WORD winColor = 7; // default gray
    switch (color) {
        case Color::Black:   winColor = 0; break;
        case Color::Red:     winColor = 4; break;
        case Color::Green:   winColor = 2; break;
        case Color::Yellow:  winColor = 6; break;
        case Color::Blue:    winColor = 1; break;
        case Color::Magenta: winColor = 5; break;
        case Color::Cyan:    winColor = 3; break;
        case Color::White:   winColor = 7; break;
        default: break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), winColor);
#else
    printf("\033[%dm", static_cast<int>(color));
#endif
}

void resetColor() {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    printf("\033[0m");
#endif
}

void printAt(int x, int y, const std::string& text, Color color) {
    moveCursor(x, y);
    setColor(color);
    std::cout << text;
    resetColor();
    std::cout.flush();
}

void clear() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, (TCHAR)' ', cellCount, homeCoords, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count);
    SetConsoleCursorPosition(hConsole, homeCoords);
#else
    printf("\033[2J\033[H"); // clear screen + move cursor home
#endif
}

void delay(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

// } // namespace termfx

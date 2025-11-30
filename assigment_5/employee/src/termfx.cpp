#include "../header/termfx.h"
#include <iostream>
#include <cstring>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <cstdio>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#endif

// UI Layout Constants
#define TABLE_ROW_SPACING 2

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
        case Color::BrightBlack:   winColor = 8; break;
        case Color::BrightRed:     winColor = 12; break;
        case Color::BrightGreen:   winColor = 10; break;
        case Color::BrightYellow:  winColor = 14; break;
        case Color::BrightBlue:    winColor = 9; break;
        case Color::BrightMagenta: winColor = 13; break;
        case Color::BrightCyan:    winColor = 11; break;
        case Color::BrightWhite:   winColor = 15; break;
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
    printf("\033[2J\033[H");
#endif
}

void delay(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

Key getKey() {
#ifdef _WIN32
    int ch = _getch();

    // Special keys (arrows, home, end)
    if (ch == 0 || ch == 224) {
        int code = _getch();
        switch (code) {
            case 72: return Key::Up;
            case 80: return Key::Down;
            case 75: return Key::Left;
            case 77: return Key::Right;
            case 71: return Key::Home;
            case 79: return Key::End;
        }
        return Key::Unknown;
    }

    // Normal keys
    switch (ch) {
        case 13:  return Key::Enter;
        case 27:  return Key::Escape;
        case 8:
        case 127: return Key::Backspace;
    }
    return Key::Unknown;

#else
    // ---------------- Linux Implementation ----------------
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int ch1 = getchar();

    // Escape sequence: ESC [ X
    if (ch1 == 27) { 
        int ch2 = getchar();
        int ch3 = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if (ch2 == '[') {
            switch (ch3) {
                case 'A': return Key::Up;
                case 'B': return Key::Down;
                case 'C': return Key::Right;
                case 'D': return Key::Left;
                case 'H': return Key::Home;
                case 'F': return Key::End;
            }
        }
        return Key::Escape;
    }

    // Enter
    if (ch1 == 10 || ch1 == 13) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return Key::Enter;
    }

    // Backspace
    if (ch1 == 127 || ch1 == 8) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return Key::Backspace;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return Key::Unknown;

#endif
}


void hideCursor() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
    printf("\033[?25l");
    fflush(stdout);
#endif
}

void showCursor() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
    printf("\033[?25h");
    fflush(stdout);
#endif
}

int getConsoleWidth() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
#endif
}

int getConsoleHeight() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
#endif
}

// Helper function to clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

// Show back button and wait for user input
void showBackButton() {
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    
    const char* backText = "Press ENTER or BACKSPACE to return";
    int x = (width - strlen(backText)) / 2;
    int y = height - 3;
    
    printAt(x, y, backText, Color::BrightYellow);
    
    bool waiting = true;
    while (waiting) {
        Key key = getKey();
        if (key == Key::Enter || key == Key::Backspace) {
            waiting = false;
        }
    }
}

// Draw menu with items
void drawMenu(const char* items[], int size, int selected) {
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    
    int startY = (height - size * TABLE_ROW_SPACING) / 2;
    
    for (int i = 0; i < size; i++) {
        int textX = (width - strlen(items[i])) / 2;
        int y = startY + i * TABLE_ROW_SPACING;
        
        Color itemColor = (i == selected) ? Color::Blue : Color::White;
        const char* cursor = (i == selected) ? ">" : " ";
        
        printAt(textX - 3, y, cursor, Color::Blue);
        printAt(textX, y, items[i], itemColor);
    }
}
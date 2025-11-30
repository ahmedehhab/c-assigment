#include "../header/Menu.h"
#include "../header/termfx.h"
#include "../header/Screen.h"

#include <cstring>
#include <iostream>

using namespace std;

namespace Menu {

static const char* menuItems[] = {
    "NEW",
    "DISPLAY",
    "EXIT"
};

static const int MENU_SIZE = 3;

Choice homeMenu() {
    hideCursor();
    clear();

    int selected = 0;

    while (true) {

        // ----- Draw Menu -----
        int width = getConsoleWidth();  
        int startY = getConsoleHeight()/2;

        clear();
        setColor(Color::BrightCyan);
        moveCursor((width - 20) / 2, 1);
        cout << "=== MINI EDITOR ===";
        resetColor();

        for (int i = 0; i < MENU_SIZE; i++) {
            int x = (width - strlen(menuItems[i])) / 2;
            int y = startY + i * 2;

            if (i == selected) {
                setColor(Color::BrightGreen);
                moveCursor(x - 3, y);
                cout << "> ";
                resetColor();
            } else {
                moveCursor(x - 3, y);
                cout << "  ";
            }

            moveCursor(x, y);
            if (i == selected)
                setColor(Color::BrightGreen);
            else
                setColor(Color::White);

            cout << menuItems[i];
            resetColor();
        }

        cout.flush();

        // ----- Input -----
        char c;
        Key key = getKey(&c);

        switch (key) {
            case Key::Up:
            case Key::Left:
                selected = (selected - 1 + MENU_SIZE) % MENU_SIZE;
                break;

            case Key::Down:
            case Key::Right:
                selected = (selected + 1) % MENU_SIZE;
                break;

            case Key::Home:
                selected = 0;
                break;

            case Key::End:
                selected = MENU_SIZE - 1;
                break;

            case Key::Enter:
                clear();
                showCursor();
                return (Choice)selected;

            case Key::Escape:
                clear();
                showCursor();
                return EXIT_APP;

            default:
                break;
        }
    }
}

}

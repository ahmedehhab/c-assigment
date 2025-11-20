#include "../header/termfx.h"
#include <iostream>
#include <string>
#include <vector>

void showBackButton() {
    clear();
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    
    std::string backText = "BACK";
    int x = (width - backText.length()) / 2;
    int y = height / 2;
    
    printAt(x, y, backText, Color::White);
    
    bool waiting = true;
    while (waiting) {
        Key key = getKey();
        if (key == Key::Enter || key == Key::Backspace) {
            waiting = false;
        }
        delay(50);
    }
}

void addScreen() {
    clear();
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    
    std::string title = "ADD SCREEN";
    int x = (width - title.length()) / 2;
    printAt(x, height / 2 - 2, title, Color::Green);
    
    showBackButton();
}

void displayScreen() {
    clear();
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    
    std::string title = "DISPLAY SCREEN";
    int x = (width - title.length()) / 2;
    printAt(x, height / 2 - 2, title, Color::Cyan);
    
    showBackButton();
}

void drawMenu(const std::vector<std::string>& items, int selected) {
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    
    int startY = (height - items.size() * 2) / 2;
    
    for (size_t i = 0; i < items.size(); i++) {
        int textX = (width - items[i].length()) / 2;
        int y = startY + i * 2;
        
        // Draw cursor for selected item
        if (i == selected) {
            printAt(textX - 3, y, ">", Color::Blue);
            printAt(textX, y, items[i], Color::Blue);
        } else {
            printAt(textX - 3, y, " ", Color::White);
            printAt(textX, y, items[i], Color::White);
        }
    }
}

int main() {
    hideCursor();  // Hide system cursor at start
    
    std::vector<std::string> menuItems = {"ADD", "DISPLAY", "ESC"};
    int selected = 0;
    bool running = true;
    
    clear();
    
    while (running) {
        drawMenu(menuItems, selected);
        
        Key key = getKey();
        
        switch (key) {
            case Key::Up:
            case Key::Left:  // Left = Up
                selected = (selected - 1 + menuItems.size()) % menuItems.size();
                break;
                
            case Key::Down:
            case Key::Right:  // Right = Down
                selected = (selected + 1) % menuItems.size();
                break;
                
            case Key::Home:
                selected = 0;  // Jump to first item
                break;
                
            case Key::End:
                selected = menuItems.size() - 1;  // Jump to last item
                break;
                
            case Key::Enter:
                if (selected == 0) { // ADD
                    addScreen();
                    clear();
                } else if (selected == 1) { // DISPLAY
                    displayScreen();
                    clear();
                } else if (selected == 2) { // ESC
                    running = false;
                }
                break;
                
            case Key::Escape:
                running = false;
                break;
                
            default:
                break;
        }
    }
    
    clear();
    showCursor();  // Show cursor back when exiting
    
    return 0;
}
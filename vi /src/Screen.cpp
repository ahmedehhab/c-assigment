#include "../header/Screen.h"
#include "../header/termfx.h"
#include <iostream>

namespace Screen {

void drawEditor(const EditorState& e) {
    clear();
    std::cout << "Mini Editor | Ctrl+S Save | Ctrl+H Home | ESC Exit\n\n";

    for (int i = 0; i < e.buffer.lineCount; i++) {
        moveCursor(0, i + 2);
        std::cout << e.buffer.lines[i];
    }

    moveCursor(e.cursor.x, e.cursor.y + 2);
    std::cout.flush();
}

void drawDisplay(const std::string& content) {
    clear();
    std::cout << "===== FILE CONTENT =====\n\n";
    std::cout << content << "\n\nPress any key...";
    std::cout.flush();

    getchar();
}

void drawHome() {
    clear();
    std::cout << "========== Mini Editor ==========\n\n";
    std::cout << "1) New\n";
    std::cout << "2) Display\n";
    std::cout << "3) Exit\n\n";
    std::cout << "Choose: ";
    std::cout.flush();
}

}

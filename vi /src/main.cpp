#include "../header/Menu.h"
#include "../header/Screen.h"
#include "../header/EditorState.h"
#include "../header/FileManager.h"
#include "../header/termfx.h"
#include<iostream>
using namespace std;

int main() {
    enableRaw();

    while (true) {
        Menu::Choice c = Menu::homeMenu();

        if (c == Menu::NEW_FILE) {
            EditorState editor;
            initEditor(editor);

            loadFile("output.txt", editor.buffer);

            while (true) {
                Screen::drawEditor(editor);

                char ch;
                Key k = getKey(&ch);

                if (k == Key::Escape) break;
                if ((unsigned char)ch == 8) break; // Ctrl+H = home

                if ((unsigned char)ch == 19) { // Ctrl+S
                    saveFile("output.txt", editor.buffer);

                    // freeze fix
                    std::cout << "\033[6n";
                    std::cout.flush();
                }

                if (k == Key::Enter) editorEnter(editor);
                else if (k == Key::Backspace) editorBackspace(editor);
                else if (k == Key::Left) editorMoveLeft(editor);
                else if (k == Key::Right) editorMoveRight(editor);
                else if (k == Key::Up) editorMoveUp(editor);
                else if (k == Key::Down) editorMoveDown(editor);
                else if (k == Key::Char) editorInsertChar(editor, ch);
            }

            freeEditor(editor);
        }

        else if (c == Menu::DISPLAY_FILE) {
            Screen::drawDisplay(readAll("output.txt"));
        }

        else break; // EXIT
    }

    disableRaw();
    clear();
    std::cout << "Goodbye!\n";

    return 0;
}

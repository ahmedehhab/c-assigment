#include "../header/termfx.h"
#include "../header/employee.h"
#include "../header/array_manager.h"
#include "../header/ui_screens.h"

int main() {
    // All variables are now local to main()
    Employee* employees = nullptr;
    int employeeCount = 0;
    int arrayCapacity = 0;
    int nextId = 1;
    
    hideCursor();
    
    const char* menuItems[MENU_SIZE] = {"ADD", "DISPLAY", "ESC"};
    int selected = 0;
    bool running = true;
    
    clear();
    
    while (running) {
        drawMenu(menuItems, MENU_SIZE, selected);
        
        Key key = getKey();
        
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
                if (selected == 0) {
                    addScreen(employees, employeeCount, arrayCapacity, nextId);
                    clear();
                } else if (selected == 1) {
                    displayScreen(employees, employeeCount, arrayCapacity);
                    clear();
                } else if (selected == 2) {
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
    
    // Free dynamic memory before exit
    delete[] employees;
    employees = nullptr;
    
    clear();
    showCursor();
    
    return 0;
}
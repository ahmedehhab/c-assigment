#include "../header/termfx.h"
#include <iostream>
#include <cstring>

// Constants for Employee struct
#define MAX_NAME_LENGTH 50
#define MAX_POSITION_LENGTH 50

// Constants for dynamic array
#define INITIAL_CAPACITY 2
#define RESIZE_MULTIPLIER 2

// UI Layout Constants
#define TITLE_ROW 2
#define FORM_START_ROW 5
#define FORM_LEFT_MARGIN 5
#define FORM_LINE_SPACING 2
#define TABLE_HEADER_ROW 5
#define TABLE_SEPARATOR_ROW 6
#define TABLE_DATA_START_ROW 8
#define TABLE_ROW_SPACING 2

// Table Column Positions
#define COL_ID 5
#define COL_NAME 12
#define COL_POSITION 35
#define COL_SALARY 60

// Delay times in milliseconds
#define ERROR_DISPLAY_DELAY 1500
#define SUCCESS_DISPLAY_DELAY 1500

// Menu constants
#define MENU_CURSOR_OFFSET 3
#define MENU_SIZE 3

// Separator line length
#define SEPARATOR_LENGTH 64

// Clear line length for error messages
#define CLEAR_LINE_LENGTH 40
#define CLEAR_SALARY_INPUT_LENGTH 30

struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char position[MAX_POSITION_LENGTH];
    double salary;
};

// Function to resize the dynamic array
void resizeArray(Employee*& employees, int& arrayCapacity, int employeeCount) {
    int newCapacity = (arrayCapacity == 0) ? INITIAL_CAPACITY : arrayCapacity * RESIZE_MULTIPLIER;
    Employee* newArray = new Employee[newCapacity];
    
    for (int i = 0; i < employeeCount; i++) {
        newArray[i] = employees[i];
    }
    
    delete[] employees;
    
    employees = newArray;
    arrayCapacity = newCapacity;
}

// Add employee to dynamic array
void addEmployee(Employee*& employees, int& employeeCount, int& arrayCapacity, const Employee& emp) {
    if (employeeCount >= arrayCapacity) {
        resizeArray(employees, arrayCapacity, employeeCount);
    }
    employees[employeeCount++] = emp;
}

void addScreen(Employee*& employees, int& employeeCount, int& arrayCapacity, int& nextId) {
    clear();
    showCursor();
    
    int width = getConsoleWidth();
    
    const char* title = "=== ADD NEW EMPLOYEE ===";
    int titleX = (width - strlen(title)) / 2;
    printAt(titleX, TITLE_ROW, title, Color::BrightCyan);
    
    // Show cancel hint
    printAt(FORM_LEFT_MARGIN, TITLE_ROW + 1, 
            "Leave empty and press Enter to cancel", 
            Color::BrightBlack);
    
    Employee emp;
    emp.id = nextId;
    
    moveCursor(FORM_LEFT_MARGIN, FORM_START_ROW);
    setColor(Color::Green);
    std::cout << "ID: " << emp.id;
    resetColor();
    
    int currentRow = FORM_START_ROW + FORM_LINE_SPACING;
    
    // Input Name
    printAt(FORM_LEFT_MARGIN, currentRow, "Name: ", Color::Green);
    std::cin.getline(emp.name, MAX_NAME_LENGTH);
    
    if (std::cin.fail()) {
        clearInputBuffer();
        std::cin.getline(emp.name, MAX_NAME_LENGTH);
    }
    
    // Check for cancel (empty input)
    if (strlen(emp.name) == 0) {
        hideCursor();
        return;
    }
    
    currentRow += FORM_LINE_SPACING;
    
    // Input Position
    printAt(FORM_LEFT_MARGIN, currentRow, "Position: ", Color::Green);
    std::cin.getline(emp.position, MAX_POSITION_LENGTH);
    
    // Check for cancel (empty input)
    if (strlen(emp.position) == 0) {
        hideCursor();
        return;
    }
    
    currentRow += FORM_LINE_SPACING;
    
    // Input Salary
    printAt(FORM_LEFT_MARGIN, currentRow, "Salary: ", Color::Green);
    
    char salaryInput[MAX_NAME_LENGTH];
    bool validSalary = false;
    
    while (!validSalary) {
        std::cin.getline(salaryInput, MAX_NAME_LENGTH);
        
        // Check for cancel (empty input)
        if (strlen(salaryInput) == 0) {
            hideCursor();
            return;
        }
        
        // Try to convert to number
        emp.salary = atof(salaryInput);
        
        if (emp.salary <= 0) {
            printAt(FORM_LEFT_MARGIN, currentRow + 1, 
                   "Error: Enter valid positive salary!", Color::Red);
            delay(ERROR_DISPLAY_DELAY);
            moveCursor(FORM_LEFT_MARGIN, currentRow + 1);
            std::cout << std::string(CLEAR_LINE_LENGTH, ' ');
            moveCursor(FORM_LEFT_MARGIN + 8, currentRow);
            std::cout << std::string(CLEAR_SALARY_INPUT_LENGTH, ' ');
            moveCursor(FORM_LEFT_MARGIN + 8, currentRow);
        } else {
            validSalary = true;
        }
    }
    
    // Add employee
    addEmployee(employees, employeeCount, arrayCapacity, emp);
    nextId++;
    
    currentRow += FORM_LINE_SPACING + 1;
    printAt(FORM_LEFT_MARGIN, currentRow, "Employee added successfully!", Color::BrightGreen);
    
    delay(SUCCESS_DISPLAY_DELAY);
    
    hideCursor();
    showBackButton();
}

void displayScreen(Employee* employees, int employeeCount, int arrayCapacity) {
    clear();
    
    int width = getConsoleWidth();
    
    const char* title = "=== ALL EMPLOYEES ===";
    int titleX = (width - strlen(title)) / 2;
    printAt(titleX, TITLE_ROW, title, Color::BrightCyan);
    
    if (employeeCount == 0) {
        printAt(FORM_LEFT_MARGIN, FORM_START_ROW, "No employees found!", Color::Red);
    } else {
        printAt(COL_ID, TABLE_HEADER_ROW, "ID", Color::BrightYellow);
        printAt(COL_NAME, TABLE_HEADER_ROW, "Name", Color::BrightYellow);
        printAt(COL_POSITION, TABLE_HEADER_ROW, "Position", Color::BrightYellow);
        printAt(COL_SALARY, TABLE_HEADER_ROW, "Salary", Color::BrightYellow);
        
        printAt(COL_ID, TABLE_SEPARATOR_ROW, 
                std::string(SEPARATOR_LENGTH, '-'), 
                Color::BrightBlack);
        
        int row = TABLE_DATA_START_ROW;
        for (int i = 0; i < employeeCount; i++) {
            Employee& emp = employees[i];
            
            moveCursor(COL_ID, row);
            setColor(Color::White);
            std::cout << emp.id;
            
            printAt(COL_NAME, row, emp.name, Color::White);
            printAt(COL_POSITION, row, emp.position, Color::White);
            
            moveCursor(COL_SALARY, row);
            setColor(Color::White);
            std::cout << "$" << emp.salary;
            resetColor();
            
            row += TABLE_ROW_SPACING;
        }
        
        row += 1;
        moveCursor(COL_ID, row);
        setColor(Color::BrightGreen);
        std::cout << "Total Employees: " << employeeCount;
        resetColor();
        
        moveCursor(COL_ID, row + 1);
        setColor(Color::BrightBlack);
        std::cout << "Array Capacity: " << arrayCapacity;
        resetColor();
    }
    
    std::cout.flush();
    showBackButton();
}

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